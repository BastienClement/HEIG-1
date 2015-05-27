//
// Created by Bastien Clément on 18.05.15.
//

#include <iostream>
#include <cstdlib>
#include "Labo_09_Verdon_Clement_Dictionnaire.h"

using namespace std;

int main() {
    Dictionnaire d;
    d.charger("dico-RTF8.txt",false);
    d.corriger("test.txt");


    cin.get();

	return EXIT_SUCCESS;
}
