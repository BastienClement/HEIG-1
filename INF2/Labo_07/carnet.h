//
// Created by Christophe on 04.05.2015.
//

#ifndef LABO_07_CARNET_H
#define LABO_07_CARNET_H

#include <vector>
#include "personne.h"

using namespace std;

struct CarnetAdresse {
public:
	/**
	 * Ecrit le contenu du carnet d'adresse dans un fichier
	 */
	void sauver(const string& nom) const;

	/**
	 * Recharge le carnet d'adresse depuis un fichier cr�� avec sauver()
	 */
	void charger(const string& nom);

	/**
	 * Affiche le contenu du carnet d'adresse
	 */
	void afficher();

	/**
	 * Ajoute une personne au carnet d'adresse
	 */
	void ajouter(const Personne& p);

private:
	/**
	 * Les donn�es du carnet d'adresse
	 */
	vector<Personne> data;

	/**
	 * Ecrit une chaine pr�fix�e de sa longueur dans un flux de sortie
	 */
	void write_string(ostream& os, const string& str) const;

	/**
	 * Lit une chaine pr�fix�e de sa longueur depuis un flux d'entr�e
	 */
	string read_string(istream& is) const;
};

#endif //LABO_07_CARNET_H
