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

//
// Deque statique, implémenté avec un buffer circulaire
//
struct DequeStatique {
private:
	// Tableau d'éléments
	Element* data;

	// Taille du buffer
	size_t taille;

	// Index du premier élément utile
	size_t debut;

	// Nombre d'élément dans le buffer
	size_t elements = 0;

	// Returne une référence vers l'élément à l'index donné
	Element& element(size_t index);
	const Element& element(size_t index) const;

public:
	DequeStatique(size_t taille = 0);
	~DequeStatique();

	// Redimensionne le tableau interne
	void resize(size_t taille);

	// Ajoute et retire des éléments à la fin du deque
	bool push_back(const Element& e);
	bool pop_back(Element& e);

	// Ajoute et retire des éléments au début du deque
	bool push_front(const Element& e);
	bool pop_front(Element& e);

	// Information d'état du deque
	bool estPlein() const;
	bool estVide() const;
	bool estPresent(const Element& e) const;
};




#endif /* LABO_04_PERETTI_CLEMENT_DEQUESTATIQUE_H_ */


