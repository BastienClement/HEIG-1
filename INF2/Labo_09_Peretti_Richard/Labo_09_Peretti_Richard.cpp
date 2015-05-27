#include <iostream>
#include <string>

#include "Labo_09_Peretti_Richard_liste.h"
#include "Labo_09_Peretti_Richard_traitement.h"

using namespace std;

int main() {

    Liste<string> liste;

	chargerTrier(liste, "test.txt");
	return 0;
}
