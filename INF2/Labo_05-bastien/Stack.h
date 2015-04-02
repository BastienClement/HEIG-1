//
//  Pile.h
//  Labo 05
//
//  Created by Bastien Clément on 01.04.15.
//  Copyright (c) 2015 Bastien Clément. All rights reserved.
//

#ifndef __Labo_05__Pile__
#define __Labo_05__Pile__

#include <stdlib.h>

typedef double number;

struct StackElement {
    number value;
    StackElement* prior;
};

struct Stack {
private:
	StackElement* top;
    size_t items;

public:
	Stack();
	~Stack();

	void push(number i);
	number pop();

	bool empty();
	size_t size();
	void clear();
	void dump();
};

#endif /* defined(__Labo_05__Pile__) */
