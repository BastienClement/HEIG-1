/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_06
 Fichier        : Labo_06_CotzaPeretti_matrice.cpp
 Auteur(s)      : Christophe Peretti et Andrea Cotza
 Date           : 27 avril 2015
 
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

Matrice genererMatrice(size_t tailleX, size_t tailleY) {
	vector<Symbol > ligne(tailleX, Symbol::MAN);
    Matrice tableau(tailleY, ligne);
	return tableau;
}

string indent(const size_t nbIndent) {
	return string (nbIndent*INDENT_SIZE, SPACE);
}

void remplirMatrice(Matrice& matrice, unsigned int nbrCellules) {
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
	
	
	for (unsigned int k = 0; k < nbrCellules; k++){
		unsigned int indiceAleat = rand() % tab.size();
		
		// On va piocher dans le tableau une coordonnée aléatoire de la matrice
		Coordonnee coord = {tab[indiceAleat].x,tab[indiceAleat].y};
		
		// Le symbole change de MAN (1) à CHECK (0) ou CROSS (2)
		unsigned int choixSymbol = 2*(rand() % 2);
		matrice[coord.y][coord.x] = (Symbol)choixSymbol; 
		
		// On supprime la ligne de coordonnee pour ne pas avoir deux fois la même
		tab.erase(tab.begin() + indiceAleat);
	}
}

void arrayToHtml (const string fileName, const Matrice& matrice) {

	ofstream fs(fileName+FILE_EXT, ios::out);

	if (!fs) {
		cout << "/!\\ Impossible de creer le fichier " << fileName << endl;
	}
	else {
		// Ecrit le de debut du tableau
		fs << "<html>" << endl;
		fs << indent(1) << "<p><b><h2>fichier ecrit en C++</h2></b></p>" << endl;
		fs << indent(1) << "<table border=1>" << endl;

		// Ecrit les lignes du tableau
		for (size_t i = 0; i < matrice.size(); i++) {
			fs << indent(2) << "<tr>" << endl;

			// Ecrit les colonnes de la ligne du tableau
			for (size_t j = 0; j < matrice.at(0).size(); j++) {
				fs << indent(3) << "<td align=center width=" << TAB_WIDTH << " height=" << TAB_HEIGHT << ">";
				fs << "<img src=\"" << matrice.at(i).at(j) << "\"/>";
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
	os << symbolName[(int)symbol];
	return os;
}