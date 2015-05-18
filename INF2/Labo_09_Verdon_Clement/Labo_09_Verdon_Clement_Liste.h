//
// Created by Bastien Clément on 18.05.15.
//

#ifndef LABO_09_VERDON_CLEMENT_LISTE_H
#define LABO_09_VERDON_CLEMENT_LISTE_H

#include <cstdlib>
#include "Labo_09_Verdon_Clement_Element.h"

template <typename T>
using Comparateur = bool (*)(const T& a, const T& b);

template <typename T>
using Parcoureur = void (*)(const T& a);


template <typename T>
class Liste {
private:
	Element<T>* tete;

public:
	Liste& operator=(const Liste& liste);
	bool existe(T element) const;
	bool inserer(T element, size_t pos);
	bool inserer(T element, Comparateur<T> comp);
	bool supprimer(Comparateur<T> comp);
	bool supprimer(size_t pos);
	bool vider();
	void parcourir(Parcoureur<T> comp) const;
	bool trier(Comparateur<T> comp);
};

#endif
