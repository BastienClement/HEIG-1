/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_06
 Fichier        : Labo_06_CotzaPeretti.cpp
 Auteur(s)      : Christophe Peretti et Andrea Cotza
 Date           : 27 avril 2015
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
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
			cout << "Entrez le nom du fichier a generer (20 car max): ";
			cin >> fileName;
			VIDER_BUFFER;
		} while (fileName.size() > 20 && cerr << "/!\\ Nom du fichier trop long");
	
		do{
			cout << "Entrez la largeur du tableau :";
			if (cin >> x){
				ok = true;
			} else {
				cin.clear();
				cerr << "/!\\ Valeur incorrecte." << endl;
				ok = false;
			}
			VIDER_BUFFER;
		} while(!ok);
		
		do{
			cout << "Entrez la hauteur du tableau :";
			if (cin >> y){
				ok = true;
			} else {
				cin.clear();
				cerr << "/!\\ Valeur incorrecte." << endl;
				ok = false;
			}
			VIDER_BUFFER;
		} while (!ok);
		
		do{
			cout << "Entrez le nombre de case a modifier (" << x*y << " max):";
			cin >> nbreCellules;
			VIDER_BUFFER;
		} while (nbreCellules > x*y && cerr << "/!\\ La grille n'est pas aussi grande.");
		
		Matrice m = genererMatrice(x,y);
		remplirMatrice(m, nbreCellules);
		arrayToHtml(fileName, m);
	
		cout << "Voulez-vous recommencer? [o/n]";
		cin >> onRecommence;
	} while(onRecommence == 'o' || onRecommence == 'O');
   return 0;
}