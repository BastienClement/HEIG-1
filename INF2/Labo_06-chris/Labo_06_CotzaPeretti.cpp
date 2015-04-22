#include <cstdlib>
#include <iostream>
#include "Labo_06_CotzaPeretti_matrice.h"
using namespace std;

int main() {
	size_t x,y;
   cout << "Entrez la largeur du tableau :";
	cin >> x;
	cout << "Entrez la hauteur du tableau :";
	cin >> y;
	
	Matrice m = genererMatrice(x,y);
	remplirMatrice(m, 20);
   return 0;
}