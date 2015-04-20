/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05 - Calculatrice Polonaise Inverse
 Fichier     : Labo_05_ClementCotza_Stack.h
 Auteur(s)   : Clément Bastien & Cotza Andrea
 Date        : 01.04.2015

 But         : Implementer une pile dynamique

 Remarque(s) : -

 Compilateur : Apple LLVM version 6.1 (clang-602.0.49), MinGW
 -----------------------------------------------------------------------------------
 */

#ifndef __Labo_05__Pile__
#define __Labo_05__Pile__

#include <stdlib.h>

typedef double number;

struct StackElement {
	number value;
	StackElement* prior;
};

struct Stack {
private:
	// Pointeur sur l'élément au sommet de la pile
	StackElement* top;

	// Nombre d'éléments dans la pile
	size_t items;

public:
	Stack();
	~Stack();

	// Ajoute une valeur sur la pile
	void push(const number i);

	// Recupere et supprime la dernière valeure empilée
	number pop();

	// Indique si la pile est vide
	bool empty() const;

	// Retourne le nb d'elements sur la pile
	size_t size() const;

	// Vide la pile
	void clear();
};

#endif /* defined(__Labo_05__Pile__) */
