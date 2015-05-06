//
// Created by Christophe on 04.05.2015.
//

#ifndef LABO_07_PERSONNE_H
#define LABO_07_PERSONNE_H

#include <string>

using namespace std;

/**
 * Repr�sente une personne du carnet d'adresse
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
	 * Les param�tres par d�faut sont utilis�s pour cr�er une personne sans information particuli�re
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
	 * Op�rateur d'assignation en profondeur
	 */
	Personne& operator=(const Personne& p);

	/**
	 * Op�rateur de comparaison entre deux personnes
	 */
	bool operator==(const Personne& p) const;
};

/**
 * Op�rateur de flux pour les Personnes
 */
ostream& operator<<(ostream& os, const Personne& p);
istream& operator>>(istream& is, Personne& p);

#endif //LABO_07_PERSONNE_H
