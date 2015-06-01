//
// Created by Bastien Clément on 18.05.15.
//

#include <iostream>
#include <cstdlib>
#include "Labo_09_Verdon_Clement_Dictionnaire.h"

using namespace std;

int main() {
    size_t choix;
    string nomFichier;
    Dictionnaire d;

    cout << "APPLICATION DICTIONNAIRE" << endl;
    cout << "========================" << endl;

    cout << endl << "Entrez le nom du dictionnaire a charger :";
    cin >> nomFichier;
    cout << "Triez le dictionnaire ? [1/0]" << endl;
    cin >> choix;

    d.charger(nomFichier,choix);

    cout << "Entrez le nom du fichier a corriger : ";
    cin >> nomFichier;

    cout << "choisissez les corrections des mots : " << endl;
    d.corriger(nomFichier);

    cout << endl << "le fichier a bien ete corriger.... [ENTER POUR TERMINER]" << endl;

    cin.get();

	return EXIT_SUCCESS;
}
