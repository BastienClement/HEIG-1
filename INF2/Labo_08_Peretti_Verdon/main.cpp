#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct morseTrad{
	int c;
	string s;
};

const size_t NBR_CARACTERE = 41;

const morseTrad TAB_TRAD_MORSE[NBR_CARACTERE] = { { ' ', "/" }, { 'a', ".-" }, { 'b', "-..." }, { 'c', "-.-." }, { 'd', "-.." }, { 'e', "." }, { 'f', "..-." },
{ 'g', "--." }, { 'h', "...." }, { 'i', ".." }, { 'j', ".---" }, { 'k', "-.-" }, { 'l', ".-.." }, { 'm', "--" },
{ 'n', "-." }, { 'o', "---" }, { 'p', ".--." }, { 'q', "--.-" }, { 'r', ".-." }, { 's', "..." }, { 't', "-" },
{ 'u', "..-" }, { 'v', "...-" }, { 'w', ".--" }, { 'x', "-..-" }, { 'y', "-.--" }, { 'z', "--.." }, { '.', ".-.-.-" },
{ ',', "--..--" }, { '?', "..--.." }, { '!', "-.-.--" }, { '(', "-.--." }, { ')', "-.--.-" }, { '&', ".-..." },
{ ':', "---..." }, { ';', "-.-.-." }, { '=', "-...-" }, { '+', ".-.-." }, { '-', "-....-" }, { '$', "...-..-" },
{ '@', ".--.-." } };

char tradMorse(const string& s){
	for (size_t i = 0; i < NBR_CARACTERE; i++)	{
		if (TAB_TRAD_MORSE[i].s == s)
			return TAB_TRAD_MORSE[i].c;
	}

	return '~';
}

string encoder(const string& chaine){
	string chaineMorse = "";
	string chaineActuelle;
	size_t taille = chaine.size();

	for (size_t i = 0; i < taille; i++){
		for (size_t j = 0; j < NBR_CARACTERE; j++){

			if (TAB_TRAD_MORSE[j].c == chaine[i]) {
				chaineMorse += TAB_TRAD_MORSE[j].s + ' ';
				break;
			}
		}
	}
	return chaineMorse;
}

string decoder(const string& s){
	string strTmp;
	string strDecode;

	for (size_t i = 0; i < s.size(); i++) {
		if (s.at(i) == ' ' && strTmp != ""){
			strDecode.push_back(tradMorse(strTmp));
			strTmp = "";
		}
		else if (s.at(i) == '/'){
			strTmp = "";
			strDecode.push_back(' ');
			i++;
		}
		else {
			strTmp.push_back(s.at(i));
		}
	}

	strDecode.push_back(tradMorse(strTmp));

	return strDecode;
}

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
				break;
			}

			cout << "1) Sauver dans un Fichier" << endl;
			cout << "2) Retour au menu" << endl;
			cout << "-----------------------------------------" << endl;

			menuOption = demandeChoix("Veuillez saisir votre choix", 2);

			if (menuOption == 1){
				cout << "Nom du fichier :";
				getline(cin, nomDuFichier);
				ofstream fichier(nomDuFichier, ios::out | ios::trunc);
				if (fichier.is_open()){
					fichier << strEntree;
				}
			}

			break;

		case 2:
		{
			cout << "Nom du fichier :";
			getline(cin, nomDuFichier);
			ifstream fichier(nomDuFichier, ios::in);

			if (fichier.is_open()) {
				while (getline(fichier, strEntree))
				{
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
