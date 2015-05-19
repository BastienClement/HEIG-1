//
// Created by Bastien Clément on 18.05.15.
//

#include "Labo_09_Verdon_Clement_Liste.h"

template <typename T>
Liste<T>::Liste() {
	debut = new Element<T>;
	fin = new Element<T>;

	*debut = { nullptr, fin };
	*fin = { debut, nullptr };
}

template <typename T>
Liste<T>::~Liste() {
	delete debut;
	delete fin;
}

template <typename T>
Liste<T>& Liste<T>::operator=(const Liste<T>& liste) {
	if (&liste != this) {
		vider();
		liste.parcourir([this](T el) {
			inserer(el);
		});
	}
}

template <typename T>
bool Liste<T>::existe(T element) const {
	for (auto cur = debut->suivant; cur != fin; cur = cur->suivant) {
		if (cur->donnee == element) {
			return true;
		}
	}
	return false;
}

template <typename T>
void Liste<T>::inserer(T valeur) {
	inserer(valeur, fin->precedent);
}

template <typename T>
bool Liste<T>::inserer(T valeur, Element<T>* apres) {
	Element<T>* element = new Element<T>;
	*element = { apres, apres->suivant, valeur };
	apres->suivant->precedent = element;
	apres->suivant = element;
}

template <typename T>
void Liste<T>::inserer(T valeur, size_t pos) {
	auto element = debut;
	for (size_t i = pos; i > 0 && element->suivant != fin; i--) {
		element = element->suivant;
	}
	inserer(valeur, element);
}

template <typename T>
void Liste<T>::inserer(T valeur, Identifieur<T> iden) {
	auto element = debut;
	while (element->suivant != fin && iden(element->suivant->donnee)) {
		element = element->suivant;
	}
	inserer(valeur, element);
}

template <typename T>
void Liste<T>::supprimer(Element<T>* element) {
	if (element == debut || element == fin)
		throw ErreurListe { "Impossible de supprimer l'élément de début ou de fin" };

	element->precedent->suivant = element->suivant;
	element->suivant->precedent = element->precedent;

	delete element;
}

template <typename T>
void Liste<T>::supprimer(Identifieur<T> iden) {
	for (auto cur = debut->suivant; cur != fin; cur = cur->suivant) {
		if (iden(cur->donnee)) {
			cur = cur->precedent;
			supprimer(cur->suivant);
		}
	}
}

template <typename T>
void Liste<T>::supprimer(size_t pos) {
	auto element = debut->suivant;
	for (size_t i = pos; i > 0 && element != fin; i--) {
		element = element->suivant;
	}
	supprimer(element);
}

template <typename T>
void Liste<T>::vider() {
	while (debut->suivant != fin) {
		supprimer(debut->suivant);
	}
}

template <typename T>
void Liste<T>::parcourir(Parcoureur<T> par) const {
	for (auto cur = debut->suivant; cur != fin; cur = cur->suivant) {
		par(cur->donnee);
	}
}

template <typename T>
void Liste<T>::trier(Comparateur<T> comp) {
	// TODO
}

template <typename T>
void Liste<T>::swap(Element<T>* a, Element<T>* b) {
	if (a == debut || a == fin || b == debut || b == fin)
		throw ErreurListe { "Impossible d'inverser l'élément de début ou de fin" };

	std::swap(a->precedent, b->precedent);
	std::swap(a->suivant, b->suivant);
	std::swap(a->precedent->suivant, b->precedent->suivant);
	std::swap(a->suivant->precedent, b->suivant->precedent);
}
