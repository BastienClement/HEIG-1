//
// Created by Christophe on 18.05.2015.
//

#ifndef LABO_09_PERETTI_RICHARD_LABO_09_PERETTI_RICHARD_LISTE_H
#define LABO_09_PERETTI_RICHARD_LABO_09_PERETTI_RICHARD_LISTE_H

typedef std::string Donnee;

template <typename T>
using comparateur = bool (*)(const T&, const T&);

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

	size_t longueur() const;

	bool existe(const T& element);

	void inserer(const T& element, const unsigned int position);

	void inserer(const T& element, comparateur<T>);

	void supprimer(const T& element, comparateur<T>);

	void vider();

	void supprimer(size_t position);

	void parcourir(void (*fonction)(T));

	template <typename U>
	void parcourir(void (*fonction)(T, U), U);

	void trier(comparateur<T>);

private:
	Element* tete = new (std::nothrow) Element;
	Element* queue = new (std::nothrow) Element;
};

#endif //LABO_09_PERETTI_RICHARD_LABO_09_PERETTI_RICHARD_LISTE_H
