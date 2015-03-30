/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_PileDynamique.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : Implémenter une Pile dynamique autour d'un Deque dynamique
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include "Labo_04_Peretti_CLEMENT_PileDynamique.h"

bool PileDynamique::empiler(const Element& e) {
	return Deque.push_back(e);
}

bool PileDynamique::depiler(Element& e) {
	return Deque.pop_back(e);
}

bool PileDynamique::estPleine() const {
	return Deque.estPlein();
}

bool PileDynamique::estVide() const {
	return Deque.estVide();
}

bool PileDynamique::estPresent(const Element& e) const {
	return Deque.estPresent(e);
}
