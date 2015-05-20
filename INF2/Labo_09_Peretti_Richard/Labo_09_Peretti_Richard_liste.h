//
// Created by Christophe on 18.05.2015.
//

#ifndef LABO_09_PERETTI_RICHARD_LABO_09_PERETTI_RICHARD_LISTE_H
#define LABO_09_PERETTI_RICHARD_LABO_09_PERETTI_RICHARD_LISTE_H

typedef std::string Donnee;

template <typename T>
using comparateur = bool (*)(const T& t1, const T& t2);

struct Element{
	Donnee Info;
	Element* precedent;
	Element* suivant;

};

template <typename T>
class Liste{
public:

	Liste& operator= (const Liste& liste);

	bool estVide() const;

	unsigned int longueur() const;

	bool existe(T element);

	bool inserer(T element, unsigned int position);

	bool inserer(T element, comparateur<T>);

	bool supprimer(comparateur<T>);

	bool vider();

	bool supprimer(unsigned int position);

	bool parcourir(void (*fonction)(T));





private:
	Element* tete;

};

#endif //LABO_09_PERETTI_RICHARD_LABO_09_PERETTI_RICHARD_LISTE_H
