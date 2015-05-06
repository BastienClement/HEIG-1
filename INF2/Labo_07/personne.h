//
// Created by Christophe on 04.05.2015.
//

#ifndef LABO_07_PERSONNE_H
#define LABO_07_PERSONNE_H

#include <string>

using namespace std;

/**
 * Représente une personne du carnet d'adresse
 */
struct Personne {
private:
	/**
	 * Informations de la personne
	 */
	string nom;
	string prenom;
	unsigned short age;

public:
	/**
	 * Constructeur
	 * Les paramètres par défaut sont utilisés pour créer une personne sans information particulière
	 * puis saisir ces informations par la suite
	 */
	Personne(const string& nom = "", const string& prenom = "", const unsigned short age = 0);

	/**
	 * Getters
	 */
	const string getNom() const;
	const string getPrenom() const;
	unsigned short getAge() const;

	/**
	 * Setters
	 */
	void setNom(const string& nom);
	void setPrenom(const string& prenom);
	void setAge(unsigned short age);

	/**
	 * Opérateur d'assignation en profondeur
	 */
	Personne& operator=(const Personne& p);

	/**
	 * Opérateur de comparaison entre deux personnes
	 */
	bool operator==(const Personne& p) const;
};

/**
 * Opérateur de flux pour les Personnes
 */
ostream& operator<<(ostream& os, const Personne& p);
istream& operator>>(istream& is, Personne& p);

#endif //LABO_07_PERSONNE_H
