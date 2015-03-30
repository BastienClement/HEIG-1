/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_PileStatique.h
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : 
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef LABO_04_PERETTI_CLEMENT_PILESTATIQUE_H_
#define LABO_04_PERETTI_CLEMENT_PILESTATIQUE_H_

#include "Labo_04_Peretti_CLEMENT_PileStatique.h"
#include "Labo_04_Peretti_CLEMENT_DequeStatique.h"

struct PileStatique {
private:
	DequeStatique Deque;

public:
	PileStatique(size_t taille = 50);

	bool empiler(const Element& e);
	bool depiler(Element& e);
	bool estPleine() const;
	bool estVide() const;
	bool estPresent(const Element& e) const;
};

#endif /* LABO_04_PERETTI_CLEMENT_PILESTATIQUE_H_ */
