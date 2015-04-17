/*
 -----------------------------------------------------------------------------------
 Laboratoire    : ASD_Labo_3
 Fichier        : labo3.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément
 -----------------------------------------------------------------------------------
 */

#include <vector>
#include <iostream>
using namespace std;

typedef unsigned char byte;

// Nous faisons des passages par copie et non par référence afin de pouvoir
// passer le même tableau à chaque fonction de tri
void selectionSort(vector<byte>& T);
void countingSort(vector<byte> T);
void quickSort(vector<byte> T);


int main(int argc, const char *argv[]) {

	vector<byte> T;
	T.push_back(3);
	T.push_back(6);
	T.push_back(4);
	T.push_back(2);
	T.push_back(9);
	T.push_back(6);
	T.push_back(8);

	cout << "tri par sélection" << endl;
	selectionSort(T);
	return 0;
}

void selectionSort(vector<byte>& T){
	size_t n = T.size();
	size_t imin;

	for (size_t i = 0; i < n-1; i++){
		// On enregistre le premier indice de la boucle courante
		imin = i;
		for (size_t j = i + 1; j < n; j++){
			//
			if (T[j] < T[imin]) imin = j;
		}
		swap(T[i],T[imin]);
	}

	for(size_t i = 0; i < n; i++){
		cout << (int)T[i] << endl;
	}
}
