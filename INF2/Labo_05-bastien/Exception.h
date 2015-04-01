//
//  Exception.h
//  Labo 05
//
//  Created by Bastien Clément on 01.04.15.
//  Copyright (c) 2015 Bastien Clément. All rights reserved.
//

#ifndef __Labo_05__Exception__
#define __Labo_05__Exception__

#include <string>
using namespace std;

struct CalculatorException {
	int code;
	string error;
	string message;
};

#endif /* defined(__Labo_05__Exception__) */
