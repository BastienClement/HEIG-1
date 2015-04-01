/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_05
 Fichier        : main.cpp
 Auteur(s)      : Bastien Clément et Andrea Cotza
 Date           : 25 mars 2015
 
 But            : 
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include "Calculator.h"
#include <iostream>
#include <string>

int main() {
	Calculator calc;
	cout << calc.eval("-2 + 3.14e4+25-.33") << endl;
	//cout << stod(".e10") << endl;
	return 0;
}
