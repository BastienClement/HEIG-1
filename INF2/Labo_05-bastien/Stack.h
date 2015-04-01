//
//  Pile.h
//  Labo 05
//
//  Created by Bastien Clément on 01.04.15.
//  Copyright (c) 2015 Bastien Clément. All rights reserved.
//

#ifndef __Labo_05__Pile__
#define __Labo_05__Pile__

#include <stack>
using namespace std;

struct Stack {
private:
	stack<int> stack;

public:
	void push(int i);
	int pop();
	void clear();
};

#endif /* defined(__Labo_05__Pile__) */
