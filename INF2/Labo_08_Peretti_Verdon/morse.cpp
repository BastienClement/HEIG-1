//
// Created by Christophe on 11.05.2015.
//

#include "morse.h"
#include <string>
#include <cstdlib>

using namespace std;

char tradMorse(const string& s){
	for (size_t i = 0; i < NBR_CARACTERE; i++)	{
		if (TAB_TRAD_MORSE[i].s == s)
			return TAB_TRAD_MORSE[i].c;
	}

	return '~';
}

string encoder(const string& chaine){
	string chaineMorse = "";
	string chaineActuelle;
	size_t taille = chaine.size();

	for (size_t i = 0; i < taille; i++){
		for (size_t j = 0; j < NBR_CARACTERE; j++){

			if (TAB_TRAD_MORSE[j].c == chaine[i]) {
				chaineMorse += TAB_TRAD_MORSE[j].s + ' ';
				break;
			}
		}
	}
	return chaineMorse;
}

string decoder(const string& s){
	string strTmp;
	string strDecode;

	for (size_t i = 0; i < s.size(); i++) {
		if (s.at(i) == ' ' && strTmp != ""){
			strDecode.push_back(tradMorse(strTmp));
			strTmp = "";
		}
		else if (s.at(i) == '/'){
			strTmp = "";
			strDecode.push_back(' ');
			i++;
		}
		else {
			strTmp.push_back(s.at(i));
		}
	}

	strDecode.push_back(tradMorse(strTmp));

	return strDecode;
}
