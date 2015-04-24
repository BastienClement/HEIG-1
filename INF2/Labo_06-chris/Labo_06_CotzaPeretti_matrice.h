/* 
 * Fichier      : Labo_06_CotzaPeretti_matrice.h
 * Auteur(s)    : Christophe Peretti
 *
 * Date         : 22. avril 2015, 11:10
 */

#ifndef LABO_06_COTZAPERETTI_MATRICE_H
#define	LABO_06_COTZAPERETTI_MATRICE_H

#include <vector>
#include <string>

using namespace std;

const size_t INDENT_SIZE = 4;
const char SPACE = ' ';
const size_t TAB_WIDTH = 100;
const size_t TAB_HEIGHT = 100;

enum Symbol {CHECK, MAN, CROSS};
static string symbolName[] {"check", "man", "cross"};

typedef std::vector<std::vector<Symbol>> Matrice;

struct Coordonnee{
	unsigned int x;
	unsigned int y;
};

string indent(const size_t nbIndent);

Matrice genererMatrice(size_t tailleX, size_t tailleY);

void remplirMatrice(Matrice& matrice, unsigned int nbrCellules);

void arrayToHtml (const char* fileName, const Matrice& matrice);

ostream& operator << (ostream& os, const Symbol symbol);

#endif	/* LABO_06_COTZAPERETTI_MATRICE_H */

