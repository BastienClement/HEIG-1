/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05 - Calculatrice Polonaise Inverse
 Fichier     : Labo_05_ClementCotza_Calculator.h
 Auteur(s)   : Clément Bastien & Cotza Andrea
 Date        : 01.04.2015

 But         : Implementer une calculatrice polonaise inverse

 Remarque(s) : -

 Compilateur : Apple LLVM version 6.1 (clang-602.0.49), MinGW
 -----------------------------------------------------------------------------------
 */

#ifndef __Labo_05__Calculatrice__
#define __Labo_05__Calculatrice__

#include <string>
#include "Labo_05_ClementCotza_Stack.h"

using namespace std;

// Types de token disponibles
enum class TokenType {
	num, op
};

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

	// Retourne le prochain token ou nullptr si la fin de l'expression est atteinte
	Token* next();

public:
	// Constructeur
	Calculator();

	// Evalue une expression et retourne le résultat
	number eval(const string& expr);
};

#endif /* defined(__Labo_05__Calculatrice__) */
