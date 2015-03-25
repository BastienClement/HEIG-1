/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_PileDynamique.h
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : 
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef LABO_04_PERETTI_CLEMENT_PILEDYNAMIQUE_H_
#define LABO_04_PERETTI_CLEMENT_PILEDYNAMIQUE_H_

#include "Labo_04_Peretti_CLEMENT.h"
#include "Labo_04_Peretti_CLEMENT_DequeDynamique.h"

struct PileDynamique {
private:
	DequeDynamique Deque;

public:
	PileDynamique();
	~PileDynamique();
	bool empiler(const Element& e);
	bool depiler(Element& e);
	bool estPleine();
	bool estVide();
	bool estPresent(const Element& e);
};

#endif /* LABO_04_PERETTI_CLEMENT_PILEDYNAMIQUE_H_ */
