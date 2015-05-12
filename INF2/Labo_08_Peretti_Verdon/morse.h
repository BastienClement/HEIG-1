//
// Created by Christophe on 11.05.2015.
//
#include <cstdlib>
#include <string>
using namespace std;

#ifndef LABO_08_PERETTI_VERDON_MORSE_H
#define LABO_08_PERETTI_VERDON_MORSE_H


struct morseTrad{
	int c;
	string s;
};

const size_t NBR_CARACTERE = 52;

const morseTrad TAB_TRAD_MORSE[NBR_CARACTERE] =
		{ { ' ', "/" }, { 'a', ".-" }, { 'b', "-..." }, { 'c', "-.-." }, { 'd', "-.." }, { 'e', "." }, { 'f', "..-." },
		  {'g', "--." }, { 'h', "...." }, { 'i', ".." }, { 'j', ".---" }, { 'k', "-.-" }, { 'l', ".-.." }, { 'm', "--" },
		  { 'n', "-." }, { 'o', "---" }, { 'p', ".--." }, { 'q', "--.-" }, { 'r', ".-." }, { 's', "..." }, { 't', "-" },
		  { 'u', "..-" }, { 'v', "...-" }, { 'w', ".--" }, { 'x', "-..-" }, { 'y', "-.--" }, { 'z', "--.." },
		  { '.', ".-.-.-" },{ ',', "--..--" }, { '?', "..--.." }, { '!', "-.-.--" }, { '!', "---." }, { '(', "-.--." },
		  { ')', "-.--.-" }, { '&', ".-..." },{ ':', "---..." }, { ';', "-.-.-." }, { '=', "-...-" }, { '+', ".-.-." },
		  { '-', "-....-" }, { '$', "...-..-" }, { '@', ".--.-." },{ '0', "-----" }, { '1', ".----" },{ '2', "..---" },
		  { '3', "...--" },{ '4', "....-" },{ '5', "....." }, { '6', "-...." }, { '7', "--..." },{ '8', "---.." },
		  { '9', "----." } };

string strToLower(string str);
char tradMorse(const string& s);
string encoder(const string& chaine);
string decoder(const string& s);


#endif //LABO_08_PERETTI_VERDON_MORSE_H
