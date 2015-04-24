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
#include <fstream>
#include "Labo_06_CotzaPeretti_matrice.h"

using namespace std;

Matrice genererMatrice(size_t tailleX, size_t tailleY){
	vector<unsigned int> ligne(tailleX, 0);
    Matrice tableau(tailleY, ligne);
	return tableau;
}

ostream indent(const size_t nbIndent) {
	ostream os;
	for (size_t i = 0; i < nbIndent; i++){
		for (size_t j = 0; j < INDENT_SIZE; i++){
			os << SPACE;
		}
	}
	return os;
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

void arrayToHtml (const char* fileName, const Matrice& matrice) {

	ofstream fs(fileName, ios::out);

	if (!fs) {
		cout << "/!\\ Impossible de creer le fichier " << filename << endl;
	}
	else {
		// Ecrit le de bebut du tableau
		fs << "<html>" << endl;
		fs << indent(1) << "<p><b><h2>fichier ecrit en C++</h2></b></p>" << endl;
		fs << indent(1) << "<table border=1>" << endl;

		// Ecrit les lignes du tableau
		for (size_t i = 0; i < matrice.size(); i++) {
			fs << indent(2) << "<tr>" << endl;

			// Ecrit les colonnes de la ligne du tableau
			for (size_t j = 0; j < matrice.at(0).size(); j++) {
				fs << indent(3) << "<td align=center width=" << TAB_WIDTH << " height=" << TAB_HEIGHT << ">";
				fs << "<img src=\"" << matrice.at(i).at(j) << "\".png/>";
				fs << "</td>" << endl;
			}
			fs << indent(2) << "</tr>" << endl;
		}
		fs << indent(1) << "</table>" << endl;
		fs << "<html>" << endl;

		fs.close();
		cout << "Le fichier " << fileName << " a bien ete genere" << endl;
	}
}

ostream& operator << (ostream& os, const Symbol symbol) {
	os << symbolName[symbol];
	return os;
}