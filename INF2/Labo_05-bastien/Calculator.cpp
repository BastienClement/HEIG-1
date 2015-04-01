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

Token::operator bool() {
	return type != TokenType::end;
}

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
	Token t;

	// Eat white-spaces
	while (pos < len && isblank(expr[pos])) pos++;

	// End of expr
	if (pos >= len) {
		t.type = TokenType::end;
		return t;
	}

	// Peek current and next char
	char c = expr[pos];
	char n = (pos + 1 < len) ? expr[pos + 1] : '\0';

	if ((isdigit(c) || c == '.') || ((c == '+' || c == '-') && (isdigit(n) || n == '.'))) {
		t.type = TokenType::num;
	} else {
		t.type = TokenType::op;
	}

	switch (t.type) {
		case TokenType::num: {
			size_t begin = pos;
			size_t length = 1;

			while (++pos < len) {
				c = expr[pos];
				if (!isdigit(c) && c != 'e' && c != '.') {
					break;
				} else {
					++length;
				}
			}

			t.data.num = stod(expr.substr(begin, length));
			break;
		}

		case TokenType::op:
			t.data.op = c;
			pos++;
			break;

		case TokenType::end: ; // Impossible
	}

	return t;
}

void Calculator::execute() {
	Token t;
	bool done = false;

	while ((t = next())) {
		if (done) {
			// Syntax error, something after =
		}

		switch (t.type) {
			case TokenType::num:
				cout << "Number: " << t.data.num << endl;
				stack.push(t.data.num);
				break;

			case TokenType::op:
				cout << "Operator: " << t.data.op << endl;
				switch (t.data.op) {
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

			case TokenType::end: ; // Impossible
		}
	}

	if (done) return;
	// Error, unexpected end of input
}

number Calculator::eval(const string& e) {
	// Vider le stack si pas déjà vide
	stack.clear();

	cout << "Expr: " << e << endl;

	expr = e;
	len = e.length();
	pos = 0;
	execute();

	return stack.pop();
}
