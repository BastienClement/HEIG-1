//
// Created by Bastien Clément on 18.05.15.
//

#include "Labo_09_Verdon_Clement_Dictionnaire.h"
#include <fstream>

void Dictionnaire::sauver(const string& nom) const {

    ofstream fichier(nom, ios::out | ios::trunc);

    if (fichier.is_open()) {
        for(Element i = mots.tete; i.suivant != nullptr; i++) {
            fichier << i.donnee;
        }
    }
}

void Dictionnaire::charger(const string& nom, bool trier = false) {

    string mot;

	ifstream fichier(nomFichier, ios::in);

	if (fichier.is_open()) {
		while (fichier >> mot) {
			this->mots->inserer(mot,0);
		}

		if(trier){
            this->mots->trier();
		}
	}

}

void Dictionnaire::afficher() const {

}

void Dictionnaire::corriger(const string& nom) const {

}
