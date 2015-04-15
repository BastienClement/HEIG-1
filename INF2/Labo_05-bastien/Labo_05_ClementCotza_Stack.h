/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05 - Calculatrice Polonaise Inverse
 Fichier     : Labo_05_ClementCotza_Stack.h
 Auteur(s)   : Clément Bastien & Cotza Andrea
 Date        : 01.04.2015

 But         : Met à disposition une pile dynamique

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
	StackElement* top;
    size_t items;

public:
	Stack();
	~Stack();

	void push(number i);
	number pop();

	bool empty();
	size_t size();
	void clear();
};

#endif /* defined(__Labo_05__Pile__) */
