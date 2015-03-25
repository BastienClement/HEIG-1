/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT_DequeDynamique.h
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015
 
 But            : 
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef LABO_04_PERETTI_CLEMENT_DEQUEDYNAMIQUE_H_
#define LABO_04_PERETTI_CLEMENT_DEQUEDYNAMIQUE_H_

#include "Labo_04_Peretti_CLEMENT.h"

// Un élément du deque dynamique
struct Noeud {
	Element valeur;
	Noeud* precedent;
	Noeud* suivant;
};

//
// Deque dynamique, implémenté comme une liste doublement chaînée circulaire
//
struct DequeDynamique {
private:
	// Pointeurs vers le premier et dernier élément
	Noeud* tete;
	Noeud* queue;

	// Crée un nouveau noeud dans la structure interne, modifie le pointeur ptr
	bool creerNoeud(const Element& e, Noeud*& ptr);

	// Supprime un noeud de la structure interne et modifie le pointeur ptr
	bool supprimerNoeud(Element& e, Noeud*& ptr);

public:
	DequeDynamique();
	~DequeDynamique();

	// Ajout et suppression à la fin du deque
	bool push_back(const Element& e);
	bool pop_back(Element& e);

	// Ajout et suppression au début du deque
	bool push_front(const Element& e);
	bool pop_front(Element& e);

	// Information d'état du deque
	bool estPlein() const;
	bool estVide() const;
	bool estPresent(const Element& e) const;
};

#endif /* LABO_04_PERETTI_CLEMENT_DEQUEDYNAMIQUE_H_ */
