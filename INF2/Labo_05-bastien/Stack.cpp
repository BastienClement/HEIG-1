//
//  Pile.cpp
//  Labo 05
//
//  Created by Bastien Clément on 01.04.15.
//  Copyright (c) 2015 Bastien Clément. All rights reserved.
//

#include "Stack.h"
#include "Exception.h"
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
		throw CalculatorException { 102, "EMPTY_STACK", "Attempted to pop a number from an empty stack" };
	}

    StackElement* element = this->top;
    number value = element->value;

	this->top = element->prior;
	delete element;
    this->items--;

	return value;
}

bool Stack::empty() {
    return (this->top == nullptr);
}

size_t Stack::size() {
	return this->items;
}

void Stack::clear() {
    StackElement* element = this->top;
    while (element != nullptr) {
        element = this->top->prior;
        delete this->top;
        this->top = element;
    }
	this->items = 0;
}
