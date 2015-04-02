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
#include <cmath>

Calculator::Calculator() {
	ans = 0;
}

void Calculator::add() {
	stack.push(stack.pop() + stack.pop());
}

void Calculator::sub() {
	number b = stack.pop();
	number a = stack.pop();
	stack.push(a - b);
}

void Calculator::mult() {
	stack.push(stack.pop() * stack.pop());
}

void Calculator::div() {
	number b = stack.pop();
	number a = stack.pop();

	if (b == 0) {
		throw CalculatorException { 12, "DIV_BY_0", "Attempted to divide by 0" };
	}

	stack.push(a / b);
}

void Calculator::mod() {
	long b = stack.pop();
	long a = stack.pop();

	if (b == 0) {
		throw CalculatorException { 13, "MOD_BY_0", "Attempted to compute the reminder of a division by 0" };
	}

	stack.push(a % b);
}

void Calculator::pow() {
	number b = stack.pop();
	number a = stack.pop();
	stack.push(::pow(a, b));
}

void Calculator::root() {
	stack.push(sqrt(stack.pop()));
}

void Calculator::rootx() {
	number b = stack.pop();
	number a = stack.pop();
	stack.push(::pow(a, 1/b));
}

void Calculator::log() {
	stack.push(::log(stack.pop()));
}

void Calculator::logx() {
	number b = stack.pop();
	number a = stack.pop();
	stack.push(::log(a) / ::log(b));
}

void Calculator::sin() {
	stack.push(::sin(stack.pop()));
}

void Calculator::cos() {
	stack.push(::cos(stack.pop()));
}

void Calculator::tan() {
	stack.push(::tan(stack.pop()));
}

void Calculator::asin() {
	stack.push(::asin(stack.pop()));
}

void Calculator::acos() {
	stack.push(::acos(stack.pop()));
}

void Calculator::atan() {
	stack.push(::atan(stack.pop()));
}

void Calculator::fac() {
	double r = 1;
	for (long i = stack.pop(); i > 0; i--) r *= i;
	stack.push(r);
}

void Calculator::swap() {
	number b = stack.pop();
	number a = stack.pop();
	stack.push(b);
	stack.push(a);
}

void Calculator::dump() {
	stack.dump();
}

static bool isnumeric(char c) {
	return isdigit(c) || c == '.';
}

Token* Calculator::next() {
	// Retire tous les espaces blancs avant le prochain token
	while (pos < len && !isgraph(expr[pos])) pos++;

	// Fin de l'expression
	if (pos >= len) {
		return nullptr;
	}

	// On récupère le caractère à la position actuelle et la suivante
	char c = expr[pos];
	char n = (pos + 1 < len) ? expr[pos + 1] : '\0';

	// Distinction entre nombre et opérateur
	if (isnumeric(c) || ((c == '+' || c == '-') && isnumeric(n))) {
		tok.type = TokenType::num;
	} else {
		tok.type = TokenType::op;
	}

	switch (tok.type) {
		// Lecture d'un nombre
		case TokenType::num: {
			// Début et longueur du nombre
			size_t begin = pos;
			size_t length = 1;

			// Tant que l'on a des caractères valides pour un nombre
			while (++pos < len) {
				c = expr[pos];
				if (!isdigit(c) && c != 'e' && c != '.') {
					break;
				} else {
					++length;
				}
			}

			// Conversion de chaine en nombre
			size_t dbl_len = 0;
			string num = expr.substr(begin, length);

			try {
				tok.data.num = stod(num, &dbl_len);
			} catch (invalid_argument) {
				dbl_len = 0;
			}

			// On s'assure d'avoir traité le nombre dans son ensemble
			if (dbl_len != length) {
				throw CalculatorException { 666, "DIABOLICAL_USER", "'" + num + "' is not a number" };
			}

			break;
		}

		// Lecture d'un opérateur
		case TokenType::op:
			tok.data.op = c;
			pos++;
			break;
	}

	// On retourne l'adresse du token
	return &tok;
}

void Calculator::execute() {
	// Le token actuel
	Token* t;

	// Fin de calcul (après =)
	bool done = false;

	while ((t = next())) {
		if (done) {
			// On a un token supplémentaire après le =
			throw CalculatorException { 42, "TOKEN_AFTER_EQ", "The = operator is not the last token in the expression" };
		}

		switch (t->type) {
			// Traitement d'un nombre
			case TokenType::num:
				// On empile !
				stack.push(t->data.num);
				break;

			// Traitement d'un opérateur
			case TokenType::op:
				switch (t->data.op) {
					// Opérations
					case '+': add(); break;
					case '-': sub(); break;
					case '*': mult(); break;
					case '/': div(); break;
					case '%': mod(); break;
					case 'p': pow(); break;
					case 'r': root(); break;
					case 'R': rootx(); break;
					case 'l': log(); break;
					case 'L': logx(); break;
					case '!': fac(); break;
					case 's': sin(); break;
					case 'c': cos(); break;
					case 't': tan(); break;
					case 'S': asin(); break;
					case 'C': acos(); break;
					case 'T': atan(); break;
					case 'x': swap(); break;
					case '?': dump(); break;

					// Constantes
					case 'P': stack.push(M_PI); break;
					case 'E': stack.push(M_E); break;

					// Dernier résultats
					case 'a': stack.push(ans); break;

					// Fin de calcul
					case '=': done = true; break;

					// Opérateur inconnu
					default:
						char error[50];
						sprintf(error, "Operator '%c' is undefined", t->data.op);
						throw CalculatorException { 43, "UNDEF_OPERATOR", error };
				}
				break;
		}
	}

	// On est arrivé à la fin de l'expression sans avoir rencontré l'opérateur =
	if (!done) throw CalculatorException { 44, "UNEXPECTED_END", "Unexpected end of input" };
}

number Calculator::eval(const string& e) {
	// Vide le stack par précaution
	stack.clear();

	// On défini l'expression traitée, sa longueur et la position actuelle
	expr = e;
	len = e.length();
	pos = 0;

	// Execution
	execute();

	// On s'assure de n'avoir qu'une seule valeur sur la pile, qui correspond au résultat
	if (stack.size() != 1) {
		throw CalculatorException { 5, "BAD_STACK_SIZE", "Computation left the stack with 0 or more than 1 elements" };
	}

	// Enregistrement du dernier résultat
	ans = stack.pop();
	return ans;
}
