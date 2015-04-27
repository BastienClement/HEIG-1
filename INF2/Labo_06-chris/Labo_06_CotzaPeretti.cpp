#include <cstdlib>
#include <iostream>
#include "Labo_06_CotzaPeretti_matrice.h"
using namespace std;


int main() {
	string fileName;
	size_t x,y;
	unsigned int nbreCellules;
	char onRecommence;
	
	do{
		do{
			cout << "Entrez le nom du fichier a generer (20 car max): ";
			cin >> fileName;
		} while (fileName.size() > 20);
	
		cout << "Entrez la largeur du tableau :";
		cin >> x;
		cout << "Entrez la hauteur du tableau :";
		cin >> y;
		
		do{
		cout << "Entrez le nombre de case a modifier (" << x*y << " max):";
		cin >> nbreCellules;
		} while (nbreCellules > x*y);
		
		Matrice m = genererMatrice(x,y);
		remplirMatrice(m, nbreCellules);
		arrayToHtml(fileName, m);
	
		cout << "Voulez-vous recommencer? [o/n]";
		cin >> onRecommence;
	} while(onRecommence == 'o' || onRecommence == 'O');
   return 0;
}