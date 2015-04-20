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

// Randomize le contenu d'un objet vector
void randomize(vector<byte>& vec, size_t items) {
	vec.clear();
	vec.resize(items);
	for (size_t i = 0; i < items; i++) {
		vec[i] = rand() % VAL_MAX;
	}
}

// Tri par sélection
template<typename RandomAccessIterator>
void selectionSort(RandomAccessIterator begin, RandomAccessIterator end) {
	for (; begin < end - 1; begin++) {
		RandomAccessIterator min = begin;
		for (RandomAccessIterator i = begin + 1; i < end; i++) {
			if (*i < *min) min = i;
		}
		swap(*min, *begin);
	}
}

// Tri par comptage
template<typename RandomAccessIterator>
void countingSort(RandomAccessIterator begin, RandomAccessIterator end) {
	// Tableau de comptage
	unsigned int count[VAL_MAX] = {};

	// Comptage des occurences
	for_each(begin, end, [&](byte v) { count[v]++; });

	// On le reconstruit dans l'ordre
	for (size_t i = 0; i < VAL_MAX; i++) {
		for (size_t n = count[i]; n > 0; n--) {
			*begin = i;
			begin++;
		}
	}
}

// Tri rapide
template<typename RandomAccessIterator>
void quickSort(RandomAccessIterator begin, RandomAccessIterator end) {
	if (begin < end) {
		// Dernier index valide
		RandomAccessIterator hi = end - 1;

		// Choix du pivot
		RandomAccessIterator p = begin + (end - begin) / 2;
		swap(*p, *hi);

		RandomAccessIterator i = begin - 1, j = hi;

		while (true) {
			do {
				i++;
			} while (*i < *hi);

			do {
				j--;
			} while (j > begin && *hi < *j);

			if (i >= j) {
				break;
			}

			swap(*i, *j);
		}

		swap(*i, *hi);

		quickSort(begin, p);
		quickSort(p + 1, end);
	}
}

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

	quickSort(T.begin(), T.end());
	for_each(T.begin(), T.end(), [](byte i) { cout << (int) i << endl; });
	return 0;
}

