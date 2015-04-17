/*
 -----------------------------------------------------------------------------------
 Laboratoire    : ASD_Labo_3
 Fichier        : labo3.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément
 -----------------------------------------------------------------------------------
 */
#include <cstdlib>
#include <vector>
#include <iostream>

#include <ctime>
#include <algorithm>
using namespace std;

typedef unsigned char byte;

// Non-inclus
const byte VAL_MAX = 100;

void selectionSort(vector<byte>& T);
void countingSort(vector<byte>& T);
void quickSort(vector<byte>& T);

void randomize(vector<byte>& vec, size_t items);

int main(int argc, const char* argv[]) {
	// Initialisation de l'aléatoire
	srand(time(NULL));

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



void randomize(vector<byte>& vec, size_t items) {
	vec.clear();
	for (size_t i = 0; i < items; i++) {
		vec.push_back(rand() % VAL_MAX);
	}
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

void countingSort(vector<byte>& T) {
	// Tableau de comptage
	unsigned int count[VAL_MAX] = {};

	// Comptage des occurences
	for_each(T.begin(), T.end(), [&](byte v) { count[v]++; });

	// On vide le tableau original
	T.clear();

	// On le reconstruit dans l'ordre
	for (size_t i = 0; i < 100; i++) {
		for (size_t n = count[i]; n > 0; n--) {
			T.push_back(i);
		}
	}
};
