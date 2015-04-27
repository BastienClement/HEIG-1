#include <cstdlib>
#include <iostream>
#include "Labo_06_CotzaPeretti_matrice.h"
using namespace std;


int main() {
	char fileName[20];
	size_t x,y;
	unsigned int nbreCellules;
	cout << "Entrez le nom du fichier a generer : ";
	cin >> fileName;
   cout << "Entrez la largeur du tableau :";
	cin >> x;
	cout << "Entrez la hauteur du tableau :";
	cin >> y;
	cout << "Entrez le nombre de case a modifier (" << x*y << " max):";
	cin >> nbreCellules;
	Matrice m = genererMatrice(x,y);
	remplirMatrice(m, nbreCellules);
    arrayToHtml(fileName, m);
    return 0;
}