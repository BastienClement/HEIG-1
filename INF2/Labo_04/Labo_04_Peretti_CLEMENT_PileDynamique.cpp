/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_PileDynamique.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : 
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include "Labo_04_Peretti_CLEMENT_PileDynamique.h"

bool PileDynamique::empiler(const Element& e) {
	return Deque.push_front(e);
}

bool PileDynamique::depiler(Element& e) {
	return Deque.pop_front(e);
}

bool PileDynamique::estPleine() {
	return Deque.estPlein();
}

bool PileDynamique::estVide() {
	return Deque.estVide();
}

bool PileDynamique::estPresent(const Element& e) {
	return Deque.estPresent(e);
}