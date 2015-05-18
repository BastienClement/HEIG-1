//
// Created by Bastien Clément on 18.05.15.
//

#ifndef LABO_09_VERDON_CLEMENT_DICTIONNAIRE_H
#define LABO_09_VERDON_CLEMENT_DICTIONNAIRE_H

#include <string>
#include "Labo_09_Verdon_Clement_Liste.h"

using namespace std;

class Dictionnaire {
private:
	Liste<string> mots;

public:
	void sauver(const string& nom) const;
	void charger(const string& nom, bool trier = false);
	void afficher() const;
	void corriger(const string& nom) const;
};

#endif
