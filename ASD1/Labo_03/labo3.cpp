/*
 -----------------------------------------------------------------------------------
 Laboratoire    : ASD_Labo_3
 Fichier        : labo3.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément
 -----------------------------------------------------------------------------------
 */

#include <vector>
#include <cstdlib>

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

	return 0;
}

void randomize(vector<byte>& vec, size_t items) {
	vec.clear();
	for (size_t i = 0; i < items; i++) {
		vec.push_back(rand() % VAL_MAX);
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
			res.push_back(i);
		}
	}
};