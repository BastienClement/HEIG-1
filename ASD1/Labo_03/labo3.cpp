/*
 -----------------------------------------------------------------------------------
 Laboratoire    : ASD_Labo_3
 Fichier        : labo3.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément et Verdon Arthur
 -----------------------------------------------------------------------------------
 */
#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstdio>
#include <functional>
#include <iomanip>

using namespace std;

typedef unsigned char byte;

const double max_time = 30;
const size_t max_iter = 100;

#define CHECK_SORTED 0

// Randomize le contenu d'un objet vector
void randomize(vector<byte>& vec, size_t items, byte max = 100) {
	vec.clear();
	vec.resize(items);
	for (size_t i = 0; i < items; i++) {
		vec[i] = rand() % max;
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
	// Recherche de l'élément le plus petit et le plus grand
	auto min = *begin, max = *end;
	for (auto i = begin; i < end; i++) {
		if (*i < min) min = *i;
		if (*i > max) max = *i;
	}

	// Tableau de comptage
	const size_t range = max - min + 1;
	vector<unsigned> count(range, 0);

	// Comptage des occurences
	for (auto i = begin; i < end; i++) {
		count[*i - min]++;
	}

	// On le reconstruit dans l'ordre
	for (size_t i = 0; i < range; i++) {
		for (size_t n = count[i]; n > 0; n--) {
			*(begin++) = i + min;
		}
	}
}

// Sélection du pivot pour QuickSort
template<typename RandomAccessIterator>
RandomAccessIterator selectPivot(const RandomAccessIterator begin, const RandomAccessIterator end) {
	RandomAccessIterator p1 = begin;
	RandomAccessIterator p2 = begin + (end - begin) / 2;
	RandomAccessIterator p3 = end - 1;

	if (*p1 < *p2) {
		if (*p2 < *p3) return p2;
		else if (*p1 < *p3) return p3;
		return p1;
	} else {
		if (*p1 < *p3) return p1;
		else if (*p2 < *p3) return p3;
		return p2;
	}
}

// Tri rapide
template<typename RandomAccessIterator>
void quickSort(RandomAccessIterator begin, RandomAccessIterator end) {
	// Dernier index valide
	RandomAccessIterator hi = end - 1;

	if (begin < hi) {
		// Choix du pivot
		RandomAccessIterator p = selectPivot(begin, end);
		swap(*p, *hi);

		RandomAccessIterator i = begin - 1, j = hi;

		while (true) {
			do {
				i++;
			} while (i < end && *i < *hi);

			do {
				j--;
			} while (j > begin && *hi < *j);

			if (i >= j) {
				break;
			}

			swap(*i, *j);
		}

		swap(*i, *hi);

		quickSort(begin, i);
		quickSort(i + 1, end);
	}
}

// Vérifie qu'une collection est triée
template<typename Iterable>
bool check_sorted(Iterable collection) {
	auto it = collection.begin(), end = collection.end();
	auto next = it;
	for (; ++next < end; it++) {
		if (*next < *it) return false;
	}
	return true;
}

// Effectue la mesure d'un algorithme, au maximum 100 itérations ou 30 secondes
double benchmark(vector<byte>& V, function<void(vector<byte>&)> fn) {
	double total = 0;
	size_t iterations = 0;

	do {
		// Copie de travail pour l'alorithme
		vector<byte> W = V;

		// Tri
		clock_t start, end;
		start = clock();
		fn(W);
		end = clock();


#if CHECK_SORTED
		// On s'assure que le résultat est trié
		assert(check_sorted(W));
#endif

		// Calcul du temps d'execution
		total += double(end - start) / CLOCKS_PER_SEC;
		iterations++;
	}
	while (total < max_time && iterations < max_iter);

	return total / iterations;
}

int main(int argc, const char* argv[]) {
	// Initialisation de l'aléatoire
	srand(time(NULL));

	cout << fixed;
	cout << setprecision(8);

	for (int i = 1; i < 8; i++) {
		// Temps d'executions
		double counting = 0, quick = 0, select = 0;

		// Vecteur de référence
		vector<byte> V;
		randomize(V, pow(10, i));

		// Tri comptage
		counting = benchmark(V, [](vector<byte>& v) { countingSort(v.begin(), v.end()); });

		// Tri rapide
		quick = benchmark(V, [](vector<byte>& v) { quickSort(v.begin(), v.end()); });

		// Tri par sélection
		if (i < 6) {
			select = benchmark(V, [](vector<byte>& v) { selectionSort(v.begin(), v.end()); });
		}

		cout << i << "\t" << counting << "\t" << quick << "\t" << select << endl;
	}

	return 0;
}

