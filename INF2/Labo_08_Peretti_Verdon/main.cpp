#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "morsewav.h"
#include "morse.h"

using namespace std;

unsigned short demandeChoix(const string& msg, const unsigned short& nbChoix) {
	int saisie;

	while (1) {
		cout << msg << ": ";
		if (cin >> saisie){
			while (cin.get() != '\n');
			if (saisie > 0 && saisie <= nbChoix)
				return (unsigned short)saisie;
		}
		else {
			cin.clear();
			while (cin.get() != '\n');
		}
		cerr << "/!\\ Choix incorrect" << endl;
	}
}

int main() {
	unsigned short menuOption;
	string nomDuFichier;
	string strEntree;

	cout << "#########################################" << endl;
	cout << "#                MORSE                  #" << endl;
	cout << "#########################################" << endl;

	while (true) {
		cout << endl;
		cout << "1) Lire Clavier" << endl;
		cout << "2) Lire Fichier" << endl;
		cout << "3) Quitter" << endl;
		cout << "-----------------------------------------" << endl;
		menuOption = demandeChoix("Veuillez saisir votre choix", 3);

		switch (menuOption) {
		case 1:
			cout << endl;
			cout << "1) Decoder du morse" << endl;
			cout << "2) Encoder du morse" << endl;
			cout << "-----------------------------------------" << endl;
			menuOption = demandeChoix("veuillez saisir votre choix", 2);

			switch (menuOption)	{
			case 1:
				getline(cin, strEntree);
				strEntree = decoder(strEntree);
				cout << strEntree << endl;
				break;
			case 2:
				getline(cin, strEntree);
				strEntree = encoder(strEntree);
				cout << strEntree << endl;
				cout << "1) Sauver dans un Fichier" << endl;
				cout << "2) Convertir en WAV" << endl;
				cout << "3) Retour au menu" << endl;
				cout << "-----------------------------------------" << endl;

				menuOption = demandeChoix("Veuillez saisir votre choix", 3);

				if (menuOption == 1){
					cout << "Nom du fichier :";
					getline(cin, nomDuFichier);
					ofstream fichier(nomDuFichier, ios::out | ios::trunc);
					if (fichier.is_open()){
						fichier << strEntree;
					}
				} else if (menuOption == 2){
					cout << "Nom du fichier :";
					getline(cin, nomDuFichier);
					morseToWave(nomDuFichier.c_str(),strEntree);
				}
				break;
			}



			break;

		case 2:
		{
			cout << "Nom du fichier :";
			getline(cin, nomDuFichier);
			ifstream fichier(nomDuFichier, ios::in);

			if (fichier.is_open()) {
				while (getline(fichier, strEntree)) {
					cout << strEntree << '\n';
				}
			}
		}
		break;

		case 3:
			return EXIT_SUCCESS;
			break;
		}

	}



	return EXIT_SUCCESS;
}
