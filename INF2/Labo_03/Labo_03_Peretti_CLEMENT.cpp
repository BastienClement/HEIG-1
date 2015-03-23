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

  
   /*
   cout << "Entrez une personne :" << endl;
   cin >> p1;
    */
   cout << "Une personne sans nom defini :" << endl;
   Personne p1 = Personne();
   cout << p1;
   cout << "------------------------------" << endl;
   cout << "Constructeur avec le nom :" << endl;
   Personne anna = Personne("Anna Conda");
   cout << anna;
   cout << "------------------------------" << endl;
   cout << "Constructeur avec nom et date:" << endl;
   p1 = Personne("Jean Veuxplus", Date(14, Mois::decembre, 1991));
   cout << p1;
   cout << "------------------------------" << endl;
   cout << "Constructeur avec nom, date, adresse:" << endl;
   p1 = Personne("Alain Becile", Date(), "chemin des Parapluies 12", "1400 Yverdon");
   cout << p1;
   cout << "------------------------------" << endl;
   cout << "Anna trouve un travail:" << endl;
   anna.setAdresseTravail("route de l'Espoir");
   anna.setVilleTravail("2000 Neuchatel");
   anna.setSalaire(4500);
   cout << anna;
   cout << "------------------------------" << endl;
   cout << "Anna change de travail:" << endl;
   anna.setAdresseTravail("");
   anna.setVilleTravail("1950 Sion");
   anna.setSalaire(5200);
   cout << anna;
   cout << "------------------------------" << endl;
   cout << "Une personne sans nom defini :" << endl;
   Personne* p2 = new Personne("Ovo, c'est de la dynamite");
   cout << *p2;
   delete p2;
   p2 = nullptr;
   

   return EXIT_SUCCESS;
}

