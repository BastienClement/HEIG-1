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

enum class TokenType { num, op, end };

struct Token {
	TokenType type;
	union {
		char op;
		number num;
	} data;
	operator bool();
};

struct Calculator {
private:
	Stack stack;

	string expr;
	size_t len;
	size_t pos;

	number ans;

	void add();
	void sub();
	void mult();
	void div();
	void mod();

	void execute();
	Token next();

public:
	Calculator();
	number eval(const string& expr);
};

#endif /* defined(__Labo_05__Calculatrice__) */
