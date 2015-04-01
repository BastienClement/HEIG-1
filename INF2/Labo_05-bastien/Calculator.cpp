//
//  Exception.cpp
//  Labo 05
//
//  Created by Bastien Clément on 01.04.15.
//  Copyright (c) 2015 Bastien Clément. All rights reserved.
//

#include "Calculator.h"
#include "Exception.h"

#include <sstream>
#include <iostream>
#include <cmath>
#include <cctype>

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

void Calculator::mod() {
	int b = stack.pop();
	int a = stack.pop();
	stack.push(a % b);
}

void Calculator::pow() {
	int b = stack.pop();
	int a = stack.pop();
	stack.push(::pow(a, b));
}

Token Calculator::next() {
	// Eat white-spaces
	while (pos < len && isblank(expr[pos])) pos++;

	// End of expr
	if (pos >= len) return { TokenType::end, "" };

	// Peek current char
	char c = expr[pos];

	return {};
}

void Calculator::execute() {
	bool done = false;
	char op;

	for (Token t = next(); ; t = next()) {
		if (done && t.type != TokenType::end) {
			// Syntax error, something after =
		}

		switch (t.type) {
			case TokenType::num:
				stack.push(stod(t.data));
				break;

			case TokenType::op:
				op = t.data[0];
				switch (op) {
					case '+': add(); break;
					case '-': sub(); break;
					case '*': mult(); break;
					case '/': div(); break;
					case '%': mod(); break;
					case '^': pow(); break;

					case '=':
						done = false;
						break;

					default:
						// Undefined operator
						;
				}
				break;

			case TokenType::end:
				if (done) return;
				// Error, unexpected end of input
				break;
		}
	}
}

number Calculator::eval(const string& e) {
	// Vider le stack si pas déjà vide
	stack.clear();

	expr = e;
	len = e.length();
	pos = 0;

	execute();

	return stack.pop();
}
