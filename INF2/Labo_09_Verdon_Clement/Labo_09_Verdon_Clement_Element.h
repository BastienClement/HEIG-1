//
// Created by Bastien Clément on 18.05.15.
//

#ifndef LABO_09_VERDON_CLEMENT_ELEMENT_H
#define LABO_09_VERDON_CLEMENT_ELEMENT_H

template <typename T>
struct Element {
	Element* precedent;
	Element* suivant;
	T donnee;
};

#endif
