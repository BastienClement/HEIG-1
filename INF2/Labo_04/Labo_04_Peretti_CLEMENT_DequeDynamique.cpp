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
	elements = 0;
}

DequeDynamique::~DequeDynamique() {
	Noeud* n = tete;
	while (n) {
		n = n->suivant;
		delete n;
	}
}

bool DequeDynamique::push_back(const Element& e) {
	// Création d'un nouveau noeud
	Noeud* n = new(nothrow) Noeud;
	if (!n) return false;

	// Initialisation du noeud avec un pointeur
	// vers la queue actuelle et aucun noeud suivant
	*n = { e, queue, nullptr };

	if (estVide()) {
		// Si le deque est vide, la nouvelle queue
		// est aussi la tête
		tete = n;
	} else {
		// Sinon on défini la nouvelle queue comme étant
		// le noeud suivant de la queue actuelle
		queue->suivant = n;
	}

	// Mise à jour de la queue
	queue = n;

	// Incrémentation du nombre d'élément
	elements++;

	return true;
}

bool DequeDynamique::pop_back(Element& e) {
	if (estVide()) return false;

	// Pointeur sur le dernier élément
	Noeud* q = queue;
	e = q->valeur;

	// On recule la queue d'un élément
	queue = queue->precedent;

	if (queue) {
		queue->suivant = nullptr;
	} else {
		tete = nullptr;
	}

	// Décrémentation du nombre d'éléments dans le deque
	elements--;

	return true;
}

bool DequeDynamique::push_front(const Element& e) {
	// Création d'un nouveau noeud
	Noeud* n = new(nothrow) Noeud;
	if (!n) return false;

	// Initialisation du noeud avec un pointeur
	// vers la tête actuelle et aucun noeud précédent
	*n = { e, nullptr, tete };

	if (estVide()) {
		// Si le deque est vide, la nouvelle tête
		// est aussi la queue
		queue = n;
	} else {
		// Sinon on défini la nouvelle tête comme étant
		// le noeud précédent de la tête actuelle
		tete->precedent = n;
	}

	// Mise à jour de la tête
	tete = n;

	// Mise à jour du nombre d'éléments
	elements++;

	return true;
}

bool DequeDynamique::pop_front(Element& e) {
	if (estVide()) return false;

	// Pointeur sur le premier élément
	Noeud* t = tete;
	e = t->valeur;

	// On avant la tête d'un élément
	tete = tete->suivant;

	if (tete) {
		tete->precedent = nullptr;
	} else {
		queue = nullptr;
	}

	// Décrémentation du nombre d'éléments dans le deque
	elements--;

	return true;
}

bool DequeDynamique::estPlein() const {
	// Un deque dynamique n'est jamais plein
	return false;
}

bool DequeDynamique::estVide() const {
	return elements == 0;
}

bool DequeDynamique::estPresent(Element e) const {
	Noeud* n = tete;
	while (n) {
		if (n->valeur == e) return true;
		n = n->suivant;
	}
	return false;
}
