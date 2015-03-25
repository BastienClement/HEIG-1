/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_DequeStatique.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : 
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include "Labo_04_Peretti_CLEMENT_DequeStatique.h"

DequeStatique::DequeStatique(size_t t) {
	data = t ? new Element[t] : nullptr;
	taille = t;
	debut = 0;
	elements = 0;
}

DequeStatique::~DequeStatique() {
	delete[] data;
}

Element& DequeStatique::element(size_t index) {
	return data[(debut + index) % taille];
}

// Redimensionnement du deque statique
void DequeStatique::resize(size_t t) {
	// Taille identique
	if (t == taille) return;

	// S'il y a trop d'éléments à copier
	if (elements > t) {
		elements = t;
	}

	// Allocation de l'espace
	Element* new_data = new Element[t];

	// Il y a des éléments à copier
	if (data) {
		for (size_t i = 0; i < elements; i++) {
			new_data[i] = element(i);
		}

		// Supression de l'ancien buffer
		delete[] data;
	}

	data = new_data;
	debut = 0;
	taille = t;
}

bool DequeStatique::push_back(const Element& e) {
	if (estPlein()) return false;
	element(elements++) = e;
	return true;
}

bool DequeStatique::pop_back(Element& e) {
	if (estVide()) return false;
	e = element(--elements);
	return true;
}

bool DequeStatique::push_front(const Element& e) {
	if (estPlein()) return false;
	debut = (debut == 0 ? taille : debut ) - 1;
	element(0) = e;
	elements++;
	return true;
}

bool DequeStatique::pop_front(Element& e) {
	if (estVide()) return false;
	e = element(0);
	elements--;
	debut = (debut + 1) % taille;
	return true;
}

bool DequeStatique::estPlein() const {
	return elements == taille;
}

bool DequeStatique::estVide() const {
	return elements == 0;
}

bool DequeStatique::estPresent(Element e) const {
	for (size_t i = 0; i < elements; i++) {
		if (data[(debut + i) % taille] == e) return true;
	}
	return false;
}

