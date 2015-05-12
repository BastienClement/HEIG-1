/*
-----------------------------------------------------------------------------------
Laboratoire : 08 - Code morse
Fichier     : Labo_08_VerdonPeretti.cpp
Auteur(s)   : Verdon & Peretti
Date        : 12.05.2015

But         :

Remarque(s) : -

Compilateur : MinGW
-----------------------------------------------------------------------------------
*/

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

			//Decodage
			case 1:
				strEntree = decoder(lireClavier());
				try{
					if (strEntree.find(CARACTERE_ERREUR_DECODAGE) != std::string::npos) throw ERREUR_DECODAGE_CHAINE;
				}
				catch (Exception e){
					e.afficherErreur();
				}
				cout << strEntree << endl;
				break;

			// Encodage
			case 2:
				strEntree = encoder(strToLower(lireClavier()));
				cout << strEntree << endl;
				cout << "1) Sauver dans un Fichier" << endl;
				cout << "2) Convertir en WAV" << endl;
				cout << "3) Retour au menu" << endl;
				cout << "-----------------------------------------" << endl;

				menuOption = demandeChoix("Veuillez saisir votre choix", 3);

				switch (menuOption){
				//Sauvegarde dans un fichier
				case 1:
				{
					cout << "Nom du fichier :";
					ofstream fichier(lireClavier(), ios::out | ios::trunc);
					
					try{
						if (fichier.is_open()){
							fichier << strEntree << endl;
						}
						else throw ERREUR_OUVERTURE_FICHIER;
					}
					catch (Exception e){
						e.afficherErreur();
					}
				}
				break;

				//Morse en audio
				case 2:
				{
					cout << "Nom du fichier :";
					morseToWave(lireClavier().c_str(), strEntree);
				}
				break;
				}// END SWITCH 3

				break;
			} // END SWITCH 2
			break;

		//Lecture du fichier
		case 2:
		{
			cout << "Nom du fichier :";
			try{
				strEntree = lireFichier(lireClavier());
				if (decoder(strEntree).find(CARACTERE_ERREUR_DECODAGE) != std::string::npos) throw ERREUR_DECODAGE_FICHIER;
			}
			catch (Exception e){
				e.afficherErreur();
			}
		}
		break;

		case 3:
			return EXIT_SUCCESS;
			break;
		}
	}// END SWITCH 1



	return EXIT_SUCCESS;
}
