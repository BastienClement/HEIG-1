/* 
 * Fichier      : Labo_03_Peretti_CLEMENT_date.h
 * Auteur(s)    : Christophe Peretti
 *
 * Date         : 11. mars 2015, 11:29
 */

#ifndef LABO_03_PERETTI_CLEMENT_DATE_H
#define	LABO_03_PERETTI_CLEMENT_DATE_H
#include <string>

enum class Mois {janvier, fevrier, mars, avril, mai, juin, juillet, 
                 aout, septembre, octobre, novembre, decembre};
const std::string TAB_MOIS[] = {"janvier", "fevrier", "mars", "avril", "mai", 
                                "juin", "juillet", "aout", "septembre", 
                                "octobre", "novembre", "decembre"};

struct tDates {
   int jour;
   Mois mois;
   int annee;
};


#endif	/* LABO_03_PERETTI_CLEMENT_DATE_H */

