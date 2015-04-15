/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05 - Calculatrice Polonaise Inverse
 Fichier     : Labo_05_ClementCotza_Exception.h
 Auteur(s)   : Clément Bastien & Cotza Andrea
 Date        : 01.04.2015

 But         : Fourni une structure pour les exeptions

 Remarque(s) : -

 Compilateur : Apple LLVM version 6.1 (clang-602.0.49), MinGW
 -----------------------------------------------------------------------------------
 */

#ifndef __Labo_05__Exception__
#define __Labo_05__Exception__

#include <string>
using namespace std;

struct CalculatorException {
	int code;
	string error;
	string message;
};

#endif /* defined(__Labo_05__Exception__) */
