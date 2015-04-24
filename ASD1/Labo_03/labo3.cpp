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
#include <cmath>
#include <cassert>
#include <cstdio>

using namespace std;

typedef unsigned char byte;

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
	// Type de la valeur pointée par l'itérateur
	typedef typename RandomAccessIterator::value_type val;

	// Recherche de l'élément le plus petit et le plus grand
	val min = numeric_limits<val>::max(), max = numeric_limits<val>::min();

	for (RandomAccessIterator i = begin; i < end; i++) {
		if (*i < min) min = *i;
		if (*i > max) max = *i;
	}

	// Tableau de comptage
	const size_t range = max - min + 1;
	vector<val> count(range, 0);

	// Comptage des occurences
	for_each(begin, end, [&](val v) { count[v - min]++; });

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

		quickSort(begin, i);
		quickSort(i + 1, end);
	}
}

double benchmark(function<void(void)> fn) {
	clock_t start, end;
	start = clock();
	fn();
	end = clock();
	return double(end - start) / CLOCKS_PER_SEC;
}

int main(int argc, const char* argv[]) {
	// Initialisation de l'aléatoire
	srand(time(NULL));

	for (int i = 2; i < 6; i++) {
		const int iter = 5;
		double select_time = 0, counting_time = 0, quick_time = 0;

		for (int j = 0; j < iter; j++) {
			// Tableau de référence
			vector<byte> R;
			randomize(R, pow(10, i));

			// Copie de travail pour les 3 algorithm
			vector<byte> S = R;
			vector<byte> C = R;
			vector<byte> Q = R;

			select_time += benchmark([&]() { selectionSort(S.begin(), S.end()); });
			counting_time += benchmark([&]() { countingSort(C.begin(), C.end()); });
			quick_time += benchmark([&]() { quickSort(Q.begin(), Q.end()); });

			// On vérifie que les trois tris ont produit le même résultat
			assert(S == C && C == Q);
		}

		select_time /= iter;
		counting_time /= iter;
		quick_time /= iter;

		printf("%d\t%lf\t%lf\t%lf\n", i, select_time, counting_time, quick_time);
		fflush(stdout);
	}

	return 0;
}

