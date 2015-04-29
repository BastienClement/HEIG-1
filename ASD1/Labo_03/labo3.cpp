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

double benchmark(function<void(void)> fn) {
	clock_t start, end;
	start = clock();
	fn();
	end = clock();
	return double(end - start) / CLOCKS_PER_SEC;
}

template<typename Iterable>
bool check_sorted(Iterable collection) {
	auto it = collection.begin(), end = collection.end();
	auto next = it;
	for (; ++next < end; it++) {
		if (*next < *it) return false;
	}
	return true;
}

int main(int argc, const char* argv[]) {
	// Initialisation de l'aléatoire
	srand(time(NULL));

	for (int i = 2; i < 8; i++) {
		const int iter = 30;
		double counting_time = 0, quick_time = 0, select_time = 0;

		for (int j = 0; j < iter; j++) {
			// Tableau de référence
			vector<byte> R;
			randomize(R, pow(10, i));

			{
				vector<byte> C = R;
				counting_time += benchmark([&]() { countingSort(C.begin(), C.end()); });
				assert(check_sorted(C));
			}

			{
				vector<byte> Q = R;
				quick_time += benchmark([&]() { quickSort(Q.begin(), Q.end()); });
				assert(check_sorted(Q));
			}

			if (i < 5) {
				vector<byte> S = R;
				select_time += benchmark([&]() { selectionSort(S.begin(), S.end()); });
				assert(check_sorted(S));
			}
		}

		select_time /= iter;
		counting_time /= iter;
		quick_time /= iter;

		printf("%d\t%f\t%f\t%f\n", i, counting_time, quick_time, select_time);
		fflush(stdout);
	}

	return 0;
}

