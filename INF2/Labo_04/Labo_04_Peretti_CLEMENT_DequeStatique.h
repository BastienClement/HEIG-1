/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_DequeStatique.h
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : 
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef LABO_04_PERETTI_CLEMENT_DEQUESTATIQUE_H_
#define LABO_04_PERETTI_CLEMENT_DEQUESTATIQUE_H_

#include "Labo_04_Peretti_CLEMENT.h"

struct DequeStatique {
private:
	Element* data;
	size_t taille;
	size_t debut;
	size_t elements = 0;

	Element& element(size_t index);

public:
	DequeStatique(size_t taille = 0);
	~DequeStatique();

	void resize(size_t taille);

	bool push_back(const Element& e);
	bool pop_back(Element& e);

	bool push_front(const Element& e);
	bool pop_front(Element& e);

	bool estPlein() const;
	bool estVide() const;
	bool estPresent(Element e) const;
};




#endif /* LABO_04_PERETTI_CLEMENT_DEQUESTATIQUE_H_ */


