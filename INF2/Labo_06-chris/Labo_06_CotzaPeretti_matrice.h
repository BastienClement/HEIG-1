/* 
 * Fichier      : Labo_06_CotzaPeretti_matrice.h
 * Auteur(s)    : Christophe Peretti
 *
 * Date         : 22. avril 2015, 11:10
 */

#ifndef LABO_06_COTZAPERETTI_MATRICE_H
#define	LABO_06_COTZAPERETTI_MATRICE_H

#include <vector>

typedef std::vector<std::vector<unsigned int>> Matrice;

struct Coordonnee{
	unsigned int x;
	unsigned int y;
};
Matrice genererMatrice(size_t tailleX, size_t tailleY);
void remplirMatrice(Matrice& matrice, unsigned int nbrCellules);
#endif	/* LABO_06_COTZAPERETTI_MATRICE_H */

