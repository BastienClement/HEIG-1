/*
-----------------------------------------------------------------------------------
Laboratoire : 08 - Code morse
Fichier     : Labo_08_VerdonPeretti_morse.h
Auteur(s)   : Verdon & Peretti
Date        : 12.05.2015

But         :

Remarque(s) : -

Compilateur : MinGW
-----------------------------------------------------------------------------------
*/

#include "morse.h"
#include <iostream>
#include <fstream>

using namespace std;

void Exception::afficherErreur(){	 
	cerr << code << " " + message << endl;
}

string strToLower(string str){
	for (size_t i = 0; i < str.size(); i++) {
		str.at(i) = tolower(str.at(i));
	}

	return str;
}

char tradMorse(const string& s){
	for (size_t i = 0; i < NBR_CARACTERE; i++)	{
		if (TAB_TRAD_MORSE[i].s == s)
			return TAB_TRAD_MORSE[i].c;
	}

	return CARACTERE_ERREUR_DECODAGE;
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
	if (strTmp != "")
		strDecode.push_back(tradMorse(strTmp));

	return strDecode;
}

string lireClavier(){
	string strEntree;
	getline(cin, strEntree);
	return strEntree;
}

string lireFichier(const string& nomFichier){
	string ligneFichier;
	string strARetourner;

	ifstream fichier(nomFichier, ios::in);
	if (fichier.is_open()) {
		while (getline(fichier, ligneFichier)) {
			strARetourner += ligneFichier;
		}
	}
	else throw ERREUR_OUVERTURE_FICHIER;

	return strARetourner;
}
