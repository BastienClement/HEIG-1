/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_QueueStatique.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : 
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include "Labo_04_Peretti_CLEMENT_QueueStatique.h"

QueueStatique::QueueStatique(size_t taille) : Deque(taille) {}

bool QueueStatique::inserer(const Element& e) {
	return Deque.push_back(e);
}

bool QueueStatique::prelever(Element& e) {
	return Deque.pop_front(e);
}

bool QueueStatique::estPleine() const {
	return Deque.estPlein();
}

bool QueueStatique::estVide() const {
	return Deque.estVide();
}

bool QueueStatique::estPresent(const Element& e) const {
	return Deque.estPresent(e);
}

