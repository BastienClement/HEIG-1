/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_DequeDynamique.h
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : 
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef LABO_04_PERETTI_CLEMENT_DEQUEDYNAMIQUE_H_
#define LABO_04_PERETTI_CLEMENT_DEQUEDYNAMIQUE_H_

#include "Labo_04_Peretti_CLEMENT.h"

//
// Un élément du Deque dynamique
//
struct Noeud {
	Element valeur;
	Noeud* precedent;
	Noeud* suivant;
};

//
// Deque dynamique, implémenté comme un liste doublement chaînée circulaire
//
struct DequeDynamique {
private:
	// Pointeur vers le premier élément
	Noeud* tete;
	Noeud* queue;

	bool creerNoeud(const Element& e, Noeud*& ptr);

public:
	DequeDynamique();
	~DequeDynamique();

	bool push_back(const Element& e);
	bool pop_back(Element& e);
	bool push_front(const Element& e);
	bool pop_front(Element& e);

	bool estPlein() const;
	bool estVide() const;
	bool estPresent(const Element& e) const;
};

#endif /* LABO_04_PERETTI_CLEMENT_DEQUEDYNAMIQUE_H_ */
