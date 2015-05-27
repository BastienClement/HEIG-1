//
// Created by Bastien Clément on 18.05.15.
//

#include "Labo_09_Verdon_Clement_Dictionnaire.h"
#include <fstream>
#include <iostream>

using namespace std;

vector<string> Dictionnaire::chercherCorrection(const string& mot){
    Liste<string> motAvant;
    Liste<string> motApres;
    vector<string> tabMot;

    this->mots.parcourir([&](string motListe){
                            if(mot.compare(motListe) >= 0){
                                motAvant.inserer(motListe);
                                if(motAvant.longueur() > 3)
                                    motAvant.supprimer((size_t)0);
                            }

                            if(mot.compare(motListe) < 0 && motApres.longueur() < 3)
                                motApres.inserer(motListe);
                          });


    motAvant.parcourir([&](string motListe){
                        tabMot.push_back(motListe);
                       });

    tabMot.push_back(mot);

    motApres.parcourir([&](string motListe){
                        tabMot.push_back(motListe);
                       });

    return tabMot;
}

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

void Dictionnaire::corriger(const string& nom) {
    string mot;
    ifstream fichier(nom, ios::in);
    Liste<string> fichierCorrection;
    unsigned short int choix;

    this->mots.trier([](const string& mot1,const string& mot2){
                        return (mot1.compare(mot2) < 0);
                     });


	if (fichier.is_open()) {
		while (fichier >> mot) {
			if(!this->mots.existe(mot)){
                vector<string> correction = this->chercherCorrection(mot);
                for(size_t i=0;i < correction.size();i++)
                    cout << i << ") " << correction.at(i) << endl;

                cin >> choix;

                fichierCorrection.inserer(correction.at(choix));

			}else
                fichierCorrection.inserer(mot);
		}//ENDWHILE
		fichier.close();

		ofstream fichier(nom, ios::out | ios::trunc);
        if (fichier.is_open()) {
            fichierCorrection.parcourir([&](string mot){fichier << mot << " ";});
        }
	}
}
