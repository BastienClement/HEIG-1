//
// Created by Bastien Clément on 18.05.15.
//

#ifndef LABO_09_VERDON_CLEMENT_LISTE_H
#define LABO_09_VERDON_CLEMENT_LISTE_H

#include <cstdlib>
#include <functional>
#include <string>
#include "Labo_09_Verdon_Clement_Element.h"

struct ErreurListe {
	std::string message;
};

template <typename T>
using Comparateur = bool (*)(const T&, const T&);

template <typename T>
using Identifieur = bool (*)(const T&);

template <typename T>
using Parcoureur = std::function<void(T)>;

template <typename T>
class Liste {
private:
	Element<T>* debut;
	Element<T>* fin;

	bool inserer(T valeur, Element<T>* apres = nullptr);
	void supprimer(Element<T>* element);
	void swap(Element<T>* a, Element<T>* b);

public:
	Liste();
	~Liste();

	Liste<T>& operator=(const Liste<T>& liste);

	bool existe(T element) const;

	void inserer(T valeur);
	void inserer(T valeur, size_t pos);
	void inserer(T valeur, Identifieur<T> iden);

	void supprimer(Identifieur<T> iden);
	void supprimer(size_t pos);

	void vider();
	void parcourir(Parcoureur<T> par) const;
	void trier(Comparateur<T> comp);
};

#endif
