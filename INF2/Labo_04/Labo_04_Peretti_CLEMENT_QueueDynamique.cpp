/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_QueueDynamique.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : 
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include "Labo_04_Peretti_CLEMENT_QueueDynamique.h"

bool QueueDynamique::inserer(const Element& e) {
	return Deque.push_back(e);
}

bool QueueDynamique::prelever(Element& e) {
	return Deque.pop_front(e);
}

bool QueueDynamique::estPleine() const {
	return Deque.estPlein();
}

bool QueueDynamique::estVide() const {
	return Deque.estVide();
}

bool QueueDynamique::estPresent(const Element& e) const {
	return Deque.estPresent(e);
}
