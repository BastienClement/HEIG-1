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


struct Stack {
    size_t items;
private:
    int* bottom;
	int* top;

public:
	Stack();
	~Stack();

	void push(int i);
	int pop();

	bool empty();
	size_t size();
	void clear();
};

#endif /* defined(__Labo_05__Pile__) */
