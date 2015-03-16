/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_03
 Fichier        : labo_03_Peretti_CLEMENT.cpp
 Auteur(s)      : Christophe Peretti
 Date           : 11. mars 2015
 
 But            :
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include "Labo_03_Peretti_CLEMENT_date.h"
#include "Labo_03_Peretti_CLEMENT_personne.h"
using namespace std;

#define VIDER_BUFFER while (cin.get() != '\n')

int main() {

   Personne p1 = Personne("Paul", Date(10, Mois::octobre, 2010), "Chemin de Moncul", "Avenue de Toncul", 5500);

   cout << p1;

   return EXIT_SUCCESS;
}

