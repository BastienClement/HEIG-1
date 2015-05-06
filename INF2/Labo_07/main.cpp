#include <iostream>
#include <stdlib.h>
#include "personne.h"
#include "carnet.h"

using namespace std;

int main() {
	cout << "Ecrire ou Lire? [e/l] ";
	char op;
	cin >> op;

	try {
		if (op == 'e') {
			CarnetAdresse ca;
			for (int i = 0; i < 3; i++) {
				Personne p;
				cin >> p;
				ca.ajouter(p);
			}
			cout << endl;
			ca.afficher();
			ca.sauver("carnet.bin");
		} else if (op == 'l') {
			CarnetAdresse ca;
			ca.charger("carnet.bin");
			ca.afficher();
		} else {
			cout << "Opération inconnue" << endl;
		}

		return EXIT_SUCCESS;
	}
	catch (ExceptionCarnet e) {
		cerr << "Erreur lors de l'execution !" << endl;
		cerr << e.message << endl;
	}

	return EXIT_FAILURE;
}

