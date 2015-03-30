/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_QueueStatique.h
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : 
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef LABO_04_PERETTI_CLEMENT_QUEUESTATIQUE_H_
#define LABO_04_PERETTI_CLEMENT_QUEUESTATIQUE_H_

#include "Labo_04_Peretti_CLEMENT.h"
#include "Labo_04_Peretti_CLEMENT_DequeStatique.h"

struct QueueStatique {
private:
	DequeStatique Deque;

public:
	QueueStatique(size_t taille = 50);

	bool inserer(const Element& e);
	bool prelever(Element& e);
	bool estPleine() const;
	bool estVide() const;
	bool estPresent(const Element& e) const;
};

#endif /* LABO_04_PERETTI_CLEMENT_QUEUESTATIQUE_H_ */
