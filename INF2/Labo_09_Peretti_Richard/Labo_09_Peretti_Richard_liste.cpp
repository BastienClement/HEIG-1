//
// Created by Christophe on 18.05.2015.
//
#include <string>
#include "Labo_09_Peretti_Richard_liste.h"

using namespace std;
template <typename T>
Liste<T>& Liste<T>::operator=(const Liste<T>& liste) {
	if (tete != liste.tete){
		vider();
	}
	if (liste.estVide()) return *this;

	Element* ptrCourant = liste.tete->suivant;

	while(ptrCourant != liste.queue){
		inserer(*ptrCourant, longueur());
		ptrCourant = ptrCourant->suivant;
	}
	return *this;
}

template <typename T>
bool Liste<T>::estVide() const {
	return longueur() > 0;
}

template <typename T>
size_t Liste<T>::longueur() const {
	if (tete->suivant == queue)
		return 0;

	Element* ptrCourant = tete->suivant;
	size_t longueur = 0;

	while (ptrCourant != queue){
		longueur++;
		ptrCourant = ptrCourant->suivant;
	}
	return longueur;
}

template <typename T>
bool Liste<T>::existe(const T& element) {
	if (tete->suivant == queue)
		return false;

	Element* ptrCourant = tete->suivant;
	while (ptrCourant != queue){
		if (ptrCourant->info == element)
			return true;
		ptrCourant = ptrCourant->suivant;
	}
	return false;
}

template <typename T>
void Liste<T>::inserer(const T& element, const size_t position) {
	Element* ptrNouvEl = new (nothrow) Element;
	Element* ptrCourant = tete;
	size_t posTemp = position > longueur() ? longueur() : position;

	while(posTemp-- > 0){
		ptrCourant = ptrCourant->suivant;
	}
	ptrNouvEl->suivant = ptrCourant->suivant;
	ptrNouvEl->precedent = ptrCourant;
	ptrCourant->suivant = ptrNouvEl;
	ptrNouvEl->suivant->precedent = ptrNouvEl;
}

template <typename T>
void Liste<T>::inserer(const T& element, comparateur<T> comparateur1) {


}

template <typename T>
void Liste<T>::supprimer(const T& element, comparateur<T> comp) {
	if (estVide()) return;

	Element* ptrCourant = tete->suivant;
	Element* ptrTemp;

	while (ptrCourant != queue){
		ptrTemp = ptrCourant->suivant;
		if (comp(ptrCourant->info, element)){
			ptrCourant->precedent->suivant = ptrCourant->suivant;
			ptrCourant->suivant->precedent = ptrCourant->precedent;
			delete ptrCourant;
		}
		ptrCourant = ptrTemp;
	}
}

template <typename T>
void Liste<T>::vider() {

}

template <typename T>
void Liste<T>::supprimer(size_t position) {

}

template <typename T>
void Liste<T>::parcourir(void (* fonction)(T)) {
    if (estVide()) return;

    Element* ptrCourant = tete->suivant;

	while (ptrCourant != queue){
		fonction(ptrCourant->info);
		ptrCourant = ptrCourant->suivant;
	}
}

template <typename T>
template <typename U>
void Liste<T>::parcourir(void (*fonction)(T, U), U a){
    if (estVide()) return;

    Element* ptrCourant = tete->suivant;

	while (ptrCourant != queue){
		fonction(ptrCourant->info, a);
		ptrCourant = ptrCourant->suivant;
	}
}

template <typename T>
void Liste<T>::trier(comparateur<T> comparateur1) {

}


