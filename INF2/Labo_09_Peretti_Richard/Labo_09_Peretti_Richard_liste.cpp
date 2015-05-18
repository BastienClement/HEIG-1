//
// Created by Christophe on 18.05.2015.
//
#include <string>
#include "Labo_09_Peretti_Richard_liste.h"

using namespace std;

typedef string Donnee;

typedef bool (*Comparateur)(const Donnee& d1, const Donnee& d2);

struct Element{
	Donnee Info;
	Element* precedent;
	Element* suivant;

};

class Liste{
public:

	Liste& operator= (const Liste& liste);

	bool estVide() const;

	unsigned int longueur() const;

	template <typename T>
	bool existe(T element);

	template <typename T>
	bool inserer(T element, unsigned int position);

	template <typename T>
	bool inserer(T element, Comparateur comp);

	template <typename T>
	bool supprimer(Comparateur comp);

	template <typename T>
	bool vider();

	template <typename T>
	bool supprimer(unsigned int position);

	template <typename T>
	bool parcourir();





private:
	Element* tete;

};
