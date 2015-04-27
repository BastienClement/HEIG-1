/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_06
 Fichier        : Labo_06_CotzaPeretti_matrice.h
 Auteur(s)      : Christophe Peretti et Andrea Cotza
 Date           : 27 avril 2015

 But            : Met a disposition les prototypes des fonctions et les objects
 				  necessaire pour la création du tableau aléatoire ainsi qu'a son
 				  ecriture dans un fichier.

 Remarques(s)   :

 Compilateur    : MinGW-g++ 4.8.1, Apple LLVM version 6.1.0 (clang-602.0.49)
 -----------------------------------------------------------------------------------
 */

#ifndef LABO_06_COTZAPERETTI_MATRICE_H
#define	LABO_06_COTZAPERETTI_MATRICE_H

#include <vector>
#include <string>

using namespace std;

const size_t INDENT_SIZE = 4;
const char SPACE = ' ';
const string FILE_EXT = ".html";
const unsigned int WIDTH_MAX = 100;
const unsigned int HEIGHT_MAX = 100;
const unsigned int CEL_WIDTH = 100;
const unsigned int CEL_HEIGHT = 100;

enum class Symbol {CHECK, MAN, CROSS};
static string symbolName[] {"check.png", "man.png", "cross.png"};

typedef std::vector<std::vector<Symbol>> Matrice;

struct Coordonnee{
	unsigned int x;
	unsigned int y;
};

string indent(const size_t nbIndent);

Matrice genererMatrice(size_t tailleX, size_t tailleY);

void remplirMatrice(Matrice& matrice, unsigned int nbrCellules);

void arrayToHtml (const string fileName, const Matrice& matrice);

ostream& operator << (ostream& os, const Symbol symbol);

#endif	/* LABO_06_COTZAPERETTI_MATRICE_H */

