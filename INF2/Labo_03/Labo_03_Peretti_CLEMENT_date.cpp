/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_03
 Fichier        : labo_03_Peretti_CLEMENT_date.cpp
 Auteur(s)      : Christophe Peretti
 Date           : 11. mars 2015
 
 But            :
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include "Labo_03_Peretti_CLEMENT_date.h"
#include <iostream>
#include <sstream>
using namespace std;

const size_t NB_MOIS = 13;
const std::string TAB_MOIS[NB_MOIS] = {
	"(invalide)", "janvier", "fevrier", "mars", "avril", "mai",
	"juin", "juillet", "aout", "septembre",
	"octobre", "novembre", "decembre"};

// Constructeurs
// Equivalents à l'appel de la méthode setDate correspondante
Date::Date(int jour, Mois mois, int annee) { setDate(jour, mois, annee); }
Date::Date(const string& str) { setDate(str); }

// Getters
int Date::getJour() const { return jour; }
Mois Date::getMois() const { return mois; }
int Date::getAnnee() const { return annee; }

// Setter pour une date complète (format jour / mois / annee)
// Appel les méthodes setJour, setMois et setAnnee
Date& Date::setDate(int jour, Mois mois, int annee) {
	return setJour(jour), setMois(mois), setAnnee(annee);
}

// Setter pour une date complète (format chaine de caractères)
Date& Date::setDate(const string& str) {
	return *this;
}

// Setter pour un jour
Date& Date::setJour(int j) {
	jour = j;
	return *this;
}

// Setter pour un mois
Date& Date::setMois(Mois m) {
	mois = m;
	return *this;
}

// Setter pour une annee
Date& Date::setAnnee(int a) {
	annee = a;
	return *this;
}

// Véréfie si la date est valide
bool Date::isValid() const {
	return false;
}

// Retourne une représentation textuelle de la date
string Date::toString() const {
	ostringstream oss;
	oss << jour << " " << mois << " " << annee;
	return oss.str();
}

// Surcharge des opértaeurs de flux
ostream& operator << (ostream& os, Mois m) { return os << TAB_MOIS[(int) m]; }
ostream& operator << (ostream& os, const Date& date) { return os << date.toString(); }

// Lecture d'un mois
std::istream& operator >> (std::istream& is, Mois& mois) {
	int st_m;

	// Tentative de lecture sous forme numérique
	if (!(cin >> st_m)) {
		// Rétablissement du flux
		cin.clear();

		// Lecture d'un mot
		string str_m;
		cin >> str_m;

		// Par défaut, mois invalide
		st_m = 0;

		// Recherche du mois correspondant
		for (int i = 0; i < NB_MOIS; i++) {
			if (TAB_MOIS[i] == str_m) {
				st_m = i;
				break;
			}
		}
	}

	// Assignation du mois correct
	mois = (st_m < NB_MOIS) ? (Mois) st_m : Mois::invalide;
	return is;
}

std::istream& operator >> (std::istream& is, Date& date) {
	return is;
}
