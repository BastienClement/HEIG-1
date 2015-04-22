/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_06
 Fichier        : Labo_06_CotzaPeretti_matrice.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 02 mars 2015
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Labo_06_CotzaPeretti_matrice.h"

using namespace std;

Matrice genererMatrice(size_t tailleX, size_t tailleY){
	vector<unsigned int> ligne(tailleX, 0);
   Matrice tableau(tailleY, ligne);
	return tableau;
}

void remplirMatrice(Matrice& matrice, unsigned int nbrCellules){
	size_t tailleX = matrice[0].size();
	size_t tailleY = matrice.size();
	
	srand (time(NULL));
	
	// Tableau qui contient toutes les coordonnees possibles de la matrice
	vector<Coordonnee> tab(tailleX*tailleY);
	for (size_t i = 0; i < tailleY; i++){
		for (size_t j = 0; j < tailleX; j++){
			tab[i*tailleX+j].x = j;
			tab[i*tailleX+j].y = i;	
		}
	}
	for (unsigned int j = 0; j < nbrCellules; j++){
		unsigned int indiceAleat = rand() % tab.size();
		Coordonnee coord = {tab[indiceAleat].x,tab[indiceAleat].y};
		cout << "[" << coord.x << "," << coord.y << "]" << endl;
		tab.erase(tab.begin() + indiceAleat);
	}
}

