/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_PileStatique.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : 
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include "Labo_04_Peretti_CLEMENT_PileStatique.h"

PileStatique::PileStatique(size_t taille) : Deque(taille) {}

bool PileStatique::empiler(const Element& e) {
	return Deque.push_back(e);
}

bool PileStatique::depiler(Element& e) {
	return Deque.pop_back(e);
}

bool PileStatique::estPleine() const {
	return Deque.estPlein();
}

bool PileStatique::estVide() const {
	return Deque.estVide();
}

bool PileStatique::estPresent(const Element& e) const {
	return Deque.estPresent(e);
}
