//
//  Exception.cpp
//  Labo 05
//
//  Created by Bastien Clément on 01.04.15.
//  Copyright (c) 2015 Bastien Clément. All rights reserved.
//

#include "Calculator.h"
#include "Exception.h"

#include <iostream>
#include <cctype>
#include <cstring>

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
		throw CalculatorException { 12, "DIV_BY_0", "Attempted to divide by 0" };
	}

	stack.push(a / b);
}

void Calculator::mod() {
	int b = stack.pop();
	int a = stack.pop();

	if (b == 0) {
		throw CalculatorException { 13, "MOD_BY_0", "Attempted to compute the reminder of a division by 0" };
	}

	stack.push(a % b);
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
			throw CalculatorException { 42, "TOKEN_AFTER_EQ", "The = operator is not the last token in the expression" };
		}

		switch (t.type) {
			case TokenType::num:
				stack.push(t.data.num);
				break;

			case TokenType::op:
				switch (t.data.op) {
					case '+': add(); break;
					case '-': sub(); break;
					case '*': mult(); break;
					case '/': div(); break;
					case '%': mod(); break;

					case '=': done = true; break;

					default:
						char error[50];
						sprintf(error, "Operator '%c' is undefined", t.data.op);
						throw CalculatorException { 43, "UNDEF_OPERATOR", error };
				}
				break;

			case TokenType::end: ; // Impossible
		}
	}

	if (!done) throw CalculatorException { 44, "UNEXPECTED_END", "Unexpected end of input" };
}

number Calculator::eval(const string& e) {
	// Vider le stack si pas déjà vide
	stack.clear();

	expr = e;
	len = e.length();
	pos = 0;
	execute();

	if (stack.size() != 1) {
		throw CalculatorException { 5, "BAD_STACK_SIZE", "Computation left the stack with 0 or more than 1 elements" };
	}

	return stack.pop();
}
