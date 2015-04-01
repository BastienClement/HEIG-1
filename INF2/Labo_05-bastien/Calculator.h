//
//  Calculatrice.h
//  Labo 05
//
//  Created by Bastien Clément on 01.04.15.
//  Copyright (c) 2015 Bastien Clément. All rights reserved.
//

#ifndef __Labo_05__Calculatrice__
#define __Labo_05__Calculatrice__

#include <string>
#include "Stack.h"

using namespace std;

// Types de token disponibles
enum class TokenType { num, op };

// Un token de la calculatrice
struct Token {
	TokenType type;
	union {
		char op;
		number num;
	} data;
};

struct Calculator {
private:
	// La pile d'opérandes
	Stack stack;

	// Le dernier token lu depuis l'expression
	Token tok;

	// L'expression à executer
	string expr;

	// La longueur de cette expression
	size_t len;

	// La position actuelle dans l'expression
	size_t pos;

	// Résultat de la dernière expression
	number ans;

	// Opérations
	void add();
	void sub();
	void mult();
	void div();
	void mod();
	void pow();
	void root();
	void rootx();
	void log();
	void exp();
	void sin();
	void cos();
	void tan();
	void asin();
	void acos();
	void atan();
	void fac();

	// Retourne le prochain token ou nullptr si la fin de l'expression est atteinte
	Token* next();

	// Execute une expression
	void execute();

public:
	// Constructeur
	Calculator();

	// Evalue une expression et retourne le résultat
	number eval(const string& expr);
};

#endif /* defined(__Labo_05__Calculatrice__) */
