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
#include "Exception.h"
#include <iostream>
#include <iomanip>

int main() {
	Calculator calc;

	cout << setprecision(20);

	while (1) {
		cout << "[calc] ";
		string expr;
		getline(cin, expr);

		if (expr.empty()) break;
		try {
			cout << calc.eval(expr) << endl;
		} catch(CalculatorException e) {
			cerr << "Error: " << e.error << " (" << e.code << ")" << endl;
			cerr << "\t" << e.message << endl;
		}
	}

	return 0;
}
