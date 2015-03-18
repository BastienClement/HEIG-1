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

// Nombre de mois (12 + invalide = 13)
const size_t NB_MOIS = 13;

// Nom des mois
static const std::string TAB_MOIS[NB_MOIS] = {
	"(invalide)", "janvier", "fevrier", "mars", "avril", "mai",
	"juin", "juillet", "aout", "septembre",
	"octobre", "novembre", "decembre"};

// Nombre de jours dans chaque mois
static int JOURS_MOIS[NB_MOIS] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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
bool Date::isValide() const {
	// Vérification du mois
	if (mois == Mois::invalide)
		return false;

	// Vérification des jours
	if (jour < 1 || jour > (mois == Mois::fevrier ? (isBissextile() ? 29 : 28) : JOURS_MOIS[(int) jour]))
		return false;

	// L'année est toujours valide
	return true;
}

// Véréfie si la date est valide
bool Date::isBissextile() const {
	return (annee % 4) || ((annee % 100 == 0) &&
						   (annee % 400)) ? false : true;
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
	int i_mois;

	// Tentative de lecture sous forme numérique
	if (!(cin >> i_mois)) {
		// Rétablissement du flux
		cin.clear();

		// Lecture d'un mot
		string str_m;
		cin >> str_m;

		// Par défaut, mois invalide
		i_mois = 0;

		// Recherche du mois correspondant
		for (int i = 0; i < NB_MOIS; i++) {
			if (TAB_MOIS[i] == str_m) {
				i_mois = i;
				break;
			}
		}
	}

	// Assignation du mois
	mois = (i_mois < NB_MOIS) ? (Mois) i_mois : Mois::invalide;
	return is;
}

std::istream& operator >> (std::istream& is, Date& date) {
	int jour;
	Mois mois;
	int annee;

	// On lit les trois composantes de la date
	cin >> jour;
	cin >> mois;
	cin >> annee;

	// Si le flux n'est pas en erreur, nous modifions la date
	if (cin.good()) {
		date.setDate(jour, mois, annee);
	}

	return is;
}
