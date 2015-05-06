#include <iostream>
#include <string>
#include <array>

using namespace std;

struct MorseTrad{
	char c;
	string s;
};

const MorseTrad TAB_TRAD[] = {{' '," / "},{'a',".-"},{'b',"-..."},{'c',"-.-."},{'d',"-.."},{'e',"."},{'f',"..-."},
							  {'g',"--."},{'h',"...."},{'i',".."},{'j',".---"},{'k',"-.-"},{'l',".-.."},{'m',"--"},
							  {'n',"-."},{'o',"---"},{'p',".--."},{'q',"--.-"},{'r',".-."},{'s',"..."},{'t',"-"},
							  {'u',"..-"},{'v',"...-"},{'w',".--"},{'x',"-..-"},{'y',"-.--"},{'z',"--.."},{'.',".-.-.-"},
							  {',',"--..--"},{'?',"..--.."},{'!',"-.-.--"},{'(',"-.--."},{')',"-.--.-"},{'&',".-..."},
							  {':',"---..."},{';',"-.-.-."},{'=',"-...-"},{'+',".-.-."},{'-',"-....-"},{'$',"...-..-"},
							  {'@',".--.-."}};
const size_t NBR_CARACTER = 41;

string encoder(const string& chaine){
	string chaineMorse = "";
	string chaineActuelle;
	size_t taille = chaine.size();

	for(size_t i = 0; i < taille; i++){
		for(size_t j = 0; j < NBR_CARACTER; j++){

			if (TAB_TRAD[j].c == chaine[i]) {
				chaineMorse += TAB_TRAD[j].s + ' ';
				break;
			}
		}
	}
	return chaineMorse;
}


int main() {
	string s = "salut sos";
	cout << encoder(s);
	return 0;
}
