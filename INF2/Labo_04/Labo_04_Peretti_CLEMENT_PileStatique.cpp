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
	return Deque.push_front(e);
}

bool PileStatique::depiler(Element& e) {
	return Deque.pop_front(e);
}

bool PileStatique::estPleine() {
	return Deque.estPlein();
}

bool PileStatique::estVide() {
	return Deque.estVide();
}

bool PileStatique::estPresent(const Element& e) {
	return Deque.estPresent(e);
}
