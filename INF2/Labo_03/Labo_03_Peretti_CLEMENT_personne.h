/* 
 * Fichier      : Labo_03_Peretti_CLEMENT_personne.h
 * Auteur(s)    : Christophe Peretti et Bastien Clément
 *
 * Date         : 23 mars 2015
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
	string ville;
	string adresseTravail;
	string villeTravail;
	unsigned int salaire;
	
public:
	Personne(string nom = "",	Date dateNaissance = Date(), string adresse = "", 
			   string ville = "", string adresseTravail = "", string villeTravail = "", 
			   unsigned int salaire = 0);

	string getNom() const;
	Date	getDateNaissance() const;
	string getAdresse() const;
	string getVille() const;
	string getAdresseTravail() const;
	string getVilleTravail() const;
	unsigned int getSalaire() const;
	
	Personne& setNom(string nom);
	Personne& setDateNaissance(Date dateNaissance);
	Personne& setAdresse(string adresse);
	Personne& setVille(string ville);
	Personne& setAdresseTravail(string adresseTravail);
	Personne& setVilleTravail(string villeTravail);
	Personne& setSalaire(unsigned int salaire);

};

	ostream& operator << (ostream& os, const Personne& p);
	istream& operator >> (istream& is, Personne& p);
#endif	/* LABO_03_PERETTI_CLEMENT_PERSONNE_H */

