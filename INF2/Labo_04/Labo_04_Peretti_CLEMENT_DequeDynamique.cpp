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

Noeud* DequeDynamique::creerNoeud(const Element& e) {
	Noeud* n = new(nothrow) Noeud;
	if (n) {
		if (tete) {
			*n = { e, queue, tete };
			queue->suivant = n;
			tete->precedent = n;
		} else {
			*n = { e, n, n };
		}
	}
	return n;
}

bool DequeDynamique::push_back(const Element& e) {
	Noeud* n = creerNoeud(e);
	if (!n) return false;
	queue = n;
	return true;
}

bool DequeDynamique::pop_back(Element& e) {
	if (estVide()) return false;

	e = queue->valeur;

	if (queue->precedent == queue) {
		// Un seul élément
		delete queue;
		tete = queue = nullptr;
	} else {
		// Au moins deux éléments
		queue->precedent->suivant = queue->suivant;
		Noeud* n = queue->suivant->precedent = queue->precedent;
		delete queue;
		queue = n;
	}

	return true;
}

bool DequeDynamique::push_front(const Element& e) {
	Noeud* n = creerNoeud(e);
	if (!n) return false;
	tete = n;
	return true;
}

bool DequeDynamique::pop_front(Element& e) {
	if (estVide()) return false;

	e = tete->valeur;

	if (tete->suivant == tete) {
		// Un seul élément
		delete tete;
		tete = queue = nullptr;
	} else {
		// Au moins deux éléments
		tete->precedent->suivant = tete->suivant;
		Noeud* n = tete->suivant->precedent = tete->precedent;
		delete tete;
		queue = n;
	}

	return true;
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