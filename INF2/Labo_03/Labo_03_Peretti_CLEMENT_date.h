/* 
 * Fichier      : Labo_03_Peretti_CLEMENT_date.h
 * Auteur(s)    : Christophe Peretti
 *
 * Date         : 11. mars 2015, 11:29
 */

#ifndef LABO_03_PERETTI_CLEMENT_DATE_H
#define	LABO_03_PERETTI_CLEMENT_DATE_H
#include <string>

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
	Date(int jour, Mois mois, int annee);
	Date(std::string str);
	
	int getJour();
	Mois getMois();
	std::string getMoisStr();
	int getAnnee();
	
	void setJour(int jour);
	void setMois(Mois mois);
	void setMoisStr(std::string str);
	void setAnnee(int annee);
	
	std::string toString();
	void fromString(std::string str);
};


#endif	/* LABO_03_PERETTI_CLEMENT_DATE_H */

