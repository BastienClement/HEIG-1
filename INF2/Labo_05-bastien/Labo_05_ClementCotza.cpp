/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05 - Calculatrice Polonaise Inverse
 Fichier     : Labo_05_ClementCotza.cpp
 Auteur(s)   : Clément Bastien & Cotza Andrea
 Date        : 01.04.2015

 But         : Effectuer des calculs simple à la façon d'une caculatrice polonaise
 			   inverse.

 Remarque(s) : -

 Compilateur : Apple LLVM version 6.1 (clang-602.0.49), MinGW
 -----------------------------------------------------------------------------------
 */

#include "Labo_05_ClementCotza_Calculator.h"
#include "Labo_05_ClementCotza_Exception.h"
#include <iostream>
#include <iomanip>

int main() {
	Calculator calc;

	cout << setprecision(15);

	// Presentation
	cout << "######################################################" << endl;
	cout << "#             Reverse Polish Calculator              #" << endl;
	cout << "######################################################" << endl;

	cout << endl;
	cout << "Avaiable operators : [+] [-] [*] [/] and [=]" 			 << endl;
	cout << "To use last result : [a]"								 << endl;
	cout << "To quit            : [ENTER] " 					     << endl;

	cout << endl;
	cout << "------------------------------------------------------" << endl;
	cout << endl;

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
