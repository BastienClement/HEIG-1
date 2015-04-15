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
		throw CalculatorException {12, "DIV_BY_0", "Attempted to divide by 0"};
	}

	stack.push(a / b);
}

static bool isnumeric(char c) {
	return isdigit(c) || c == '.';
}

Token *Calculator::next() {
	// Retire tous les espaces blancs avant le prochain token
	while (pos < len && !isgraph(expr[pos])) pos++;

	// Fin de l'expression
	if (pos >= len) {
		return nullptr;
	}

	// On récupère le caractère à la position actuelle et la suivante
	char c = expr[pos];
	char n = (pos + 1 < len) ? (char) expr[pos + 1] : '\0';

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
				throw CalculatorException {666, "DIABOLICAL_USER", "'" + num + "' is not a number"};
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

number Calculator::eval(const string &e) {
	// Vide la pile par précaution
	stack.clear();

	// On défini l'expression courante, sa longueur et la position actuelle
	expr = e;
	len = e.length();
	pos = 0;

	// Pointeur vers token traité actuellement
	Token *t;

	// Fin de calcul (après =)
	bool done = false;

	// On traite chaque élément de l'expression
	while ((t = next())) {
		if (done) {
			// On a un token supplémentaire après le =
			throw CalculatorException {42, "TOKEN_AFTER_EQ", "The = operator is not the last token in the expression"};
		}

		switch (t->type) {
			case TokenType::num: // Traitement d'un nombre
				// On empile !
				stack.push(t->data.num);
				break;

			case TokenType::op: // Traitement d'un opérateur
				switch (t->data.op) {
					// Opérations
					case '+': add(); break;
					case '-': sub(); break;
					case '*': mult(); break;
					case '/': div(); break;
					case 'a': stack.push(ans); break;
					case '=': done = true; break;
					default: { // Opérateur inconnu
						char error[50];
						sprintf(error, "Operator '%c' is undefined", t->data.op);
						throw CalculatorException {43, "UNDEF_OPERATOR", error};
					}
				}
				break;
		}
	}

	// On est arrivé à la fin de l'expression sans avoir rencontré l'opérateur =
	if (!done) throw CalculatorException {44, "UNEXPECTED_END", "Unexpected end of input"};

	// On s'assure de n'avoir qu'une seule valeur sur la pile, qui correspond au résultat
	if (stack.size() != 1) {
		char error[100];
		sprintf(error, "Expression ended with %d value%s (instead of 1) on the stack", stack.size(), stack.size() > 0 ? "s" : "");
		throw CalculatorException {5, "BAD_STACK_SIZE", error};
	}

	// Enregistrement du dernier résultat
	ans = stack.pop();
	return ans;
}
