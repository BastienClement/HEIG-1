/* 
 * Fichier      : Labo_03_Peretti_CLEMENT_date.h
 * Auteur(s)    : Christophe Peretti
 *
 * Date         : 11. mars 2015, 11:29
 */

#ifndef LABO_03_PERETTI_CLEMENT_DATE_H
#define	LABO_03_PERETTI_CLEMENT_DATE_H
#include <string>
#include <iostream>

enum class Mois {
	janvier, fevrier, mars, avril, mai, juin, juillet,
	aout, septembre, octobre, novembre, decembre
};

struct Date {
private:
	int jour;
	Mois mois;
	int annee;
	
public:
	// Constructeurs
	Date(int jour = 1, Mois mois = Mois::janvier, int annee = 2000);
	Date(const std::string& str);

	// Getters
	int getJour() const;
	Mois getMois() const;
	int getAnnee() const;

	// Setters pour la date complète
	Date& setDate(int jour, Mois mois, int annee);
	Date& setDate(const std::string& str);

	// Setters pour un membre particulier
	Date& setJour(int jour);
	Date& setMois(Mois mois);
	Date& setAnnee(int annee);

	// Vérifie la validité d'une date
	bool isValid() const;
	operator bool() const;

	// Retourne la représentation textuelle d'une date
	std::string toString() const;
	operator std::string() const;
};

std::ostream& operator << (std::ostream& os, Mois mois);
std::ostream& operator << (std::ostream& os, const Date& date);

#endif	/* LABO_03_PERETTI_CLEMENT_DATE_H */

