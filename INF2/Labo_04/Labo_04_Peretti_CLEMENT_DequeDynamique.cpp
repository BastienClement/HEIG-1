/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_DequeDynamique.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : 
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include "Labo_04_Peretti_CLEMENT_DequeDynamique.h"
#include <new>

DequeDynamique::DequeDynamique() {
	tete = nullptr;
	queue = nullptr;
}

DequeDynamique::~DequeDynamique() {
	if (tete) {
		// On détache le dernier noeud de la chaine
		queue->suivant = nullptr;

		Noeud* c = tete;
		Noeud* n;

		while (c) {
			n = c->suivant;
			delete c;
			c = n;
		}
	}
}

bool DequeDynamique::creerNoeud(const Element& e, Noeud*& ptr) {
	Noeud* n = new(nothrow) Noeud;
	if (n) {
		if (tete) {
			*n = { e, queue, tete };
			queue->suivant = n;
			tete->precedent = n;
			ptr = n;
		} else {
			*n = { e, n, n };
			tete = queue = n;
		}
	}
	return n;
}

bool DequeDynamique::supprimerNoeud(Element& e, Noeud*& ptr) {
	if (estVide()) return false;

	e = ptr->valeur;

	if (ptr->suivant == ptr) {
		// Un seul élément
		delete ptr;
		tete = queue = nullptr;
	} else {
		// Au moins deux éléments
		ptr->precedent->suivant = ptr->suivant;
		ptr->suivant->precedent = ptr->precedent;
		delete ptr;
		if (ptr == tete) {
			tete = queue->suivant;
		} else {
			queue = tete->precedent;
		}
	}

	return true;
}

bool DequeDynamique::push_back(const Element& e) {
	return creerNoeud(e, queue);
}

bool DequeDynamique::pop_back(Element& e) {
	return supprimerNoeud(e, queue);
}

bool DequeDynamique::push_front(const Element& e) {
	return creerNoeud(e, tete);
}

bool DequeDynamique::pop_front(Element& e) {
	return supprimerNoeud(e, tete);
}

bool DequeDynamique::estPlein() const {
	// Un deque dynamique n'est jamais plein
	return false;
}

bool DequeDynamique::estVide() const {
	return tete == nullptr;
}

bool DequeDynamique::estPresent(const Element& e) const {
	if (estVide()) return false;

	Noeud* n = tete;
	do {
		if (n->valeur == e) {
			queue->suivant = tete;
			return true;
		}
		n = n->suivant;
	} while(n != tete);

	return false;
}
