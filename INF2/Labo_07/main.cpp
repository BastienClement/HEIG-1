#include <iostream>
#include "personne.h"
#include "carnet.h"

using namespace std;

int main() {
	CarnetAdresse ca;

	for (int i = 0; i < 3; i++) {
		Personne p;
		cin >> p;
		ca.ajouter(p);
	}

	ca.afficher();
	ca.sauver("test");

	cout << "---" << endl;

	CarnetAdresse ca2;
	ca2.charger("test");
	ca2.afficher();
}

