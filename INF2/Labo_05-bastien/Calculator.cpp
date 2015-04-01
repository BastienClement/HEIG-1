//
//  Exception.cpp
//  Labo 05
//
//  Created by Bastien Clément on 01.04.15.
//  Copyright (c) 2015 Bastien Clément. All rights reserved.
//

#include "Calculator.h"
#include "Exception.h"

void Calculator::add() {
	stack.push(stack.pop() + stack.pop());
}

void Calculator::sub() {
	int b = stack.pop();
	int a = stack.pop();
	stack.push(a - b);
}

void Calculator::mult() {
	stack.push(stack.pop() * stack.pop());
}

void Calculator::div() {
	int b = stack.pop();
	int a = stack.pop();

	if (b == 0) {
		// Throw
	}

	stack.push(a / b);
}

int Calculator::eval(string expr) {
	// Vider le stack si pas déjà vide
	stack.clear();

	return stack.pop();
}