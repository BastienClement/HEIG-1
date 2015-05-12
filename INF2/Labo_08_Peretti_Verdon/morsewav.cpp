#include "morsewav.h"
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <string>
#include <iostream>

#define FWRITE(buf,size) \
    wav_size += size; \
    if (fwrite(buf, size, 1, file) != 1) { \
        fprintf(stderr, "Write failed: %s\n", path); \
        exit(1); \
    }

using namespace std;

double Wpm = 20;      // words per minute
double Tone = 900;    // tone frequency (Hz)
double Sps = 44100;   // samples per second (WAV file, sound card)
// Note 60 seconds = 1 minute and 50 elements = 1 morse word.
double Bit = 1.2 / Wpm;     // duration of basic morse element,cell,quantum (seconds)
//double Eps = Wpm / 1.2;    // elements per second (frequency of morse coding)


int pcm_count;
int wav_size;

short *pcm_data;

typedef unsigned short WORD;
typedef unsigned int DWORD;

typedef struct _wave {
    WORD  wFormatTag;      // format type
    WORD  nChannels;       // number of channels (i.e. mono, stereo...)
    DWORD nSamplesPerSec;  // sample rate
    DWORD nAvgBytesPerSec; // for buffer estimation
    WORD  nBlockAlign;     // block size of data
    WORD  wBitsPerSample;  // number of bits per sample of mono data
} WAVE;

void tone (const int on_off)
{
    double ampl = 0.85 * 32767;
    double pi = 3.1415926535;
    double w = 2.0 * pi * Tone;
    int i, n, size;
    static int seconds;

    if (pcm_data == NULL) {
        seconds = 1;
        size = (int) (Sps * sizeof pcm_data[0] * seconds);
        pcm_data = (short int *)malloc(size);
    }

    n = (int) (Bit * Sps);
    for (i = 0; i < n; i += 1) {
        double t = (double)i / Sps;
        if (pcm_count == Sps * seconds) {
            seconds += 1;
            size = (int) (Sps * sizeof pcm_data[0] * seconds);
            pcm_data = (short int *)realloc(pcm_data, size);
        }
        pcm_data[pcm_count++] = (short) (on_off * ampl * sin(w * t));
    }
}

//
// Define dit, dah, end of letter, end of word.
//
// The rules of 1/3 and 1/2/4:
//   Morse code is: tone for one unit (dit) or three units (dah)
//   followed by the sum of one unit of silence (always),
//   plus two units of silence (if end of letter or if begin a word),
//   plus two units of silence (if also end of word).
//

void dit() { tone(1); tone(0); }
void dah() { tone(1); tone(1); tone(1); tone(0); }
void eol() { tone(0); tone(0); }
void eow() { tone(0); tone(0); }

void morse_to_tone(const string morse)
{
    size_t str_len = morse.length();
    for (size_t i=0; i < str_len; i++)
    {
        switch (morse[i])
        {
            case '.' : dit(); break;
            case '-' : dah(); break;
            case ' ' : eol(); break;
            case '/' : eow(); break;
            throw "UNKNOW CHAR";
        }
    }
}



void wav_write (const char *path , short *data, const int count)
{
    int data_size, wave_size, riff_size;
    FILE *file;
    WAVE wave;



    if ((file = fopen(path, "wb")) == NULL) {
        fprintf(stderr, "Open failed: %s\n", path);
        exit(1);
    }


    wave.wFormatTag      = 0x1;
    wave.nChannels       = 1;
    wave.wBitsPerSample  = sizeof data[0] * 8;
    wave.nBlockAlign     = WORD(sizeof data[0] * wave.nChannels);
    wave.nSamplesPerSec  = (int)Sps;
    wave.nAvgBytesPerSec = (int)Sps * wave.nBlockAlign;

    wave_size = sizeof wave;
    data_size = count * wave.nChannels * (wave.wBitsPerSample / 8);
    riff_size = 20 + wave_size + data_size;
    FWRITE("RIFF", 4);
    FWRITE(&riff_size, 4);

    FWRITE("WAVE", 4);
    FWRITE("fmt ", 4);
    FWRITE(&wave_size, 4);
    FWRITE(&wave, wave_size);

    FWRITE("data", 4);
    FWRITE(&data_size, 4);
    FWRITE(data, data_size);

    fclose(file);
}

void morseToWave(const char*  file,
                 const string morse)
{
    morse_to_tone(morse);
    wav_write(file, pcm_data, pcm_count);
}
