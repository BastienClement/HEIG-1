/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05 - Calculatrice Polonaise Inverse
 Fichier     : Labo_05_ClementCotza_Stack.cpp
 Auteur(s)   : Clément Bastien & Cotza Andrea
 Date        : 01.04.2015

 But         : Implementer une pile dynamique

 Remarque(s) : -

 Compilateur : Apple LLVM version 6.1 (clang-602.0.49), MinGW
 -----------------------------------------------------------------------------------
 */

#include "Labo_05_ClementCotza_Stack.h"
#include "Labo_05_ClementCotza_Exception.h"
#include <iostream>

using namespace std;

Stack::Stack() {
	this->top = nullptr;
	this->items = 0;
}

Stack::~Stack() {
	this->clear();
}

void Stack::push(number i) {
	StackElement* newElement = new StackElement;
	newElement->value = i;
	newElement->prior = this->top;

	this->top = newElement;
	this->items++;
}

number Stack::pop() {
	if (this->empty()) {
		throw CalculatorException {102, "EMPTY_STACK", "Attempted to pop a number from an empty stack"};
	}

	StackElement* element = this->top;
	number value = element->value;

	this->top = element->prior;
	delete element;
	this->items--;

	return value;
}

bool Stack::empty() const {
	return this->items == 0;
}

size_t Stack::size() const {
	return this->items;
}

void Stack::clear() {
	if (!empty()) {
		StackElement* element = this->top;
		while (element != nullptr) {
			element = this->top->prior;
			delete this->top;
			this->top = element;
		}
		this->items = 0;
	}
}
