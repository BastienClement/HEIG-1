/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_06
 Fichier        : Labo_06_CotzaPeretti.cpp
 Auteur(s)      : Christophe Peretti et Andrea Cotza
 Date           : 27 avril 2015

 But            : Generer un tableau html avec des valeur aleatoire et le sauvegarder
 				  dans un fichier.
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1, Apple LLVM version 6.1.0 (clang-602.0.49)
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include "Labo_06_CotzaPeretti_matrice.h"
using namespace std;

#define VIDER_BUFFER while (cin.get() != '\n')

int main() {
	string fileName;
	size_t x,y;
	unsigned int nbreCellules;
	char onRecommence;
	bool ok;
	
	do{
		do{
			cout << "Entrez le nom du fichier a generer (1-20 car max): ";
			cin >> fileName;
			VIDER_BUFFER;
		} while ((fileName.size() > 20 || fileName.size() < 1) && cerr << "/!\\ Nom du fichier trop long");
	
		do{
			cout << "Entrez la largeur du tableau (1-" << WIDTH_MAX << "):";
			ok = false;
			if (cin >> x){
				if (x > 0 && x <= WIDTH_MAX)
					ok = true;
			} else {
				cin.clear();
			}
			VIDER_BUFFER;
		} while(!ok && cerr << "/!\\ Valeur incorrecte." << endl);
		
		do{
			cout << "Entrez la hauteur du tableau (1-" << HEIGHT_MAX << "):";
			ok = false;
			if (cin >> y){
				if (y > 0 && y <= HEIGHT_MAX)
					ok = true;
			} else {
				cin.clear();
			}
			VIDER_BUFFER;
		} while (!ok && cerr << "/!\\ Valeur incorrecte." << endl);
		
		do{
			cout << "Entrez le nombre de case a modifier (" << x*y << " max):";
			cin >> nbreCellules;
			VIDER_BUFFER;
		} while (nbreCellules > x*y && cerr << "/!\\ La grille n'est pas aussi grande." << endl);
		
		Matrice m = genererMatrice(x,y);
		remplirMatrice(m, nbreCellules);
		arrayToHtml(fileName, m);
	
		cout << "Voulez-vous recommencer? [o/n]";
		cin >> onRecommence;
	} while(onRecommence == 'o' || onRecommence == 'O');
   return 0;
}