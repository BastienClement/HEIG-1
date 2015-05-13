/*
-----------------------------------------------------------------------------------
Laboratoire : 08 - Code morse
Fichier     : Labo_08_VerdonPeretti_morse.cpp
Auteur(s)   : Verdon & Peretti
Date        : 12.05.2015

But         : librairie permettant de decoder et encoder du morse

Remarque(s) : -

Compilateur : MinGW
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <string>
using namespace std;

#ifndef LABO_08_PERETTI_VERDON_MORSE_H
#define LABO_08_PERETTI_VERDON_MORSE_H


struct morseTrad{
	int c;
	string s;
};

struct Exception {
public:
	int code;
	string message;
	void afficherErreur();
};

const Exception ERREUR_DECODAGE_FICHIER = { 1, "Probleme lors du decodage du fichier" };
const Exception ERREUR_OUVERTURE_FICHIER = { 2, "Erreur lors de l'ouverture du fichier" };
const Exception ERREUR_DECODAGE_CHAINE = { 3, "Erreur lors de du decodage de la chaine" };

const char CARACTERE_ERREUR_DECODAGE = '~';
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

// Convertit tous les caractere d une string en minuscule
string strToLower(string str);
//Traduit une string en morse
char tradMorse(const string& s);
//encode une string en morse
string encoder(const string& chaine);
//decode du morse une string
string decoder(const string& s);
// lit une entree clavier
string lireClavier();
// lit un fichier
string lireFichier(const string& nomFichier);


#endif //LABO_08_PERETTI_VERDON_MORSE_H
