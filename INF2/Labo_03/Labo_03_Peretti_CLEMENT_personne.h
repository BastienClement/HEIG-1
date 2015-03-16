/* 
 * Fichier      : Labo_03_Peretti_CLEMENT_personne.h
 * Auteur(s)    : Christophe Peretti
 *
 * Date         : 11. mars 2015, 11:29
 */

#ifndef LABO_03_PERETTI_CLEMENT_PERSONNE_H
#define	LABO_03_PERETTI_CLEMENT_PERSONNE_H

#include <string>
#include <iostream>
#include "Labo_03_Peretti_CLEMENT_date.h"
using namespace std;

struct Personne {
private:
	string nom;
	Date dateNaissance;
	string adresse;
	string adresseTravail;
	unsigned int salaire;
	
public:
	Personne(string nom = "",	Date dateNaissance = Date(), string adresse = "", 
			   string adresseTravail = "", unsigned int salaire = 0);

	string getNom() const;
	Date	getDateNaissance() const;
	string getAdresse() const;
	string getAdresseTravail() const;
	unsigned int getSalaire() const;
	
	Personne& setNom(string nom);
	Personne& setDateNaissance(Date dateNaissance);
	Personne& setAdresse(string adresse);
	Personne& setAdresseTravail(string adresseTravail);
	Personne& setSalaire(unsigned int salaire);

};

	ostream& operator << (ostream& os, const Personne& p);
	istream& operator >> (istream& is, Personne& p);
#endif	/* LABO_03_PERETTI_CLEMENT_PERSONNE_H */

