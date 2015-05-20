//
// Created by Bastien Clément on 18.05.15.
//

#include "Labo_09_Verdon_Clement_Dictionnaire.h"
#include <fstream>
#include <iostream>

using namespace std;

void Dictionnaire::sauver(const string& nom) const {

    ofstream fichier(nom, ios::out | ios::trunc);

    if (fichier.is_open()) {
        this->mots.parcourir([&](string mot){fichier << mot << endl;});
    }
}

void Dictionnaire::charger(const string& nom, bool trier) {

    string mot;

	ifstream fichier(nom, ios::in);

	if (fichier.is_open()) {
		while (fichier >> mot) {
			this->mots.inserer(mot);
		}

		if(trier){
            this->mots.trier([](const string& mot,const string& mot2){return mot.size() < mot2.size();});
		}
	}

}

void Dictionnaire::afficher() const {
    this->mots.parcourir([&](string mot){cout << mot << endl;});
}

void Dictionnaire::corriger(const string& nom) const {

}
