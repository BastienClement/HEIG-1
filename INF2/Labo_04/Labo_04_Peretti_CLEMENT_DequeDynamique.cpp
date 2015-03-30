/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_DequeDynamique.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : Implémenter un Deque dynamique
 
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
	// Désallocation uniquement si au moins un élément est alloué
	if (tete) {
		// On détache le dernier noeud de la chaine pour
		// simplifier la boucle
		queue->suivant = nullptr;

		// Noeud courrant
		Noeud* c = tete;

		// Noeud suivant
		Noeud* n;

		while (c) {
			n = c->suivant;
			delete c;
			c = n;
		}
	}
}

bool DequeDynamique::creerNoeud(const Element& e, Noeud*& ptr) {
	// Allocation du noeud
	Noeud* n = new(nothrow) Noeud;

	// On s'assure que l'allocation a réussi
	if (n) {
		if (tete) {
			// Il y a au moins un élément dans la structure
			// On insère notre nouveau noeud entre la queue et la tête
			*n = { e, queue, tete };

			// Mise à jour des pointeurs
			queue->suivant = n;
			tete->precedent = n;

			// Mise à jour de la tête ou de la queue
			ptr = n;
		} else {
			// La structure est vide, le noeud pointe vers lui même dans
			// les deux directions
			*n = { e, n, n };

			// La tête et la queue pointent sur le même élément
			tete = queue = n;
		}
	}

	// Cast implicite en bool
	return n;
}

bool DequeDynamique::supprimerNoeud(Element& e, Noeud*& ptr) {
	// Impossible de supprimer un noeud si la structure est vide
	if (estVide()) return false;

	// On extrait la valeur qui nous intéresse
	e = ptr->valeur;

	if (ptr->suivant == ptr) {
		// Un seul élément dans la structure
		// On supprimer l'élément
		delete ptr;

		// La tête et la queue pointent vers nullptr
		tete = queue = nullptr;
	} else {
		// Au moins deux éléments dans la structure
		// Mise à jour des liens pour "sauter" l'élément courrant
		ptr->precedent->suivant = ptr->suivant;
		ptr->suivant->precedent = ptr->precedent;

		// On supprimer l'élément
		delete ptr;

		// Mise à jour du pointeur tete ou queue vers
		// le noeud le remplaçant
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
	} while(n != tete); // On boucle tant que l'on est pas de retour à la tête

	return false;
}
