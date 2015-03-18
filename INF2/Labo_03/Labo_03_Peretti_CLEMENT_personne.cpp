/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_03
 Fichier        : labo_03_Peretti_CLEMENT_personne.cpp
 Auteur(s)      : Christophe Peretti
 Date           : 11. mars 2015
 
 But            :
 
 Remarques(s)   :
 
 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Labo_03_Peretti_CLEMENT_personne.h"
#include "Labo_03_Peretti_CLEMENT_date.h"

using namespace std;

#define VIDER_BUFFER while (cin.get() != '\n')

Personne::Personne(string nom2, Date dateNaissance2, string adresse2, string ville2,
                   string adresseTravail2, string villeTravail2, unsigned int salaire2) {
   nom = nom2;
   dateNaissance = dateNaissance2;
   adresse = adresse2;
   ville = ville2;
   adresseTravail = adresseTravail2;
   villeTravail = villeTravail2;
   salaire = salaire2;
}
// Getters
string Personne::getNom() const { return nom; }
Date Personne::getDateNaissance() const { return dateNaissance; }
string Personne::getAdresse() const { return adresse; }
string Personne::getVille() const { return ville; }
string Personne::getAdresseTravail() const { return adresseTravail; }
string Personne::getVilleTravail() const { return villeTravail; }
unsigned int Personne::getSalaire() const { return salaire; }

// Setters
Personne& Personne::setNom(const string nom2) {
   nom = nom2;
   return *this;
}

Personne& Personne::setDateNaissance(const Date dateNaissance2) {
   dateNaissance = dateNaissance2;
   return *this;
}

Personne& Personne::setAdresse(const string adresse2) {
   adresse = adresse2;
   return *this;
}

Personne& Personne::setVille(const string ville2) {
   ville = ville2;
   return *this;
}

Personne& Personne::setAdresseTravail(const string adresseTravail2) {
   adresseTravail = adresseTravail2;
   return *this;
}

Personne& Personne::setVilleTravail(const string villeTravail2) {
   villeTravail = villeTravail2;
   return *this;
}

Personne& Personne::setSalaire(const unsigned int salaire2) {
   salaire = salaire2;
   return *this;
}


ostream& operator<<(ostream& os, const Personne& p) {
   if (p.getNom() != "") {
      os << p.getNom() << endl;
   }
   os << p.getDateNaissance() << endl;
   if (p.getAdresse() != "") {
      os << p.getAdresse() << endl;
   }
   if (p.getVille() != "") {
      os << p.getVille() << endl;
   }
   if (p.getAdresseTravail() != "") {
      os << p.getAdresseTravail() << endl;
   }
   if (p.getVilleTravail() != "") {
      os << p.getVilleTravail() << endl;
   }
   if (p.getSalaire() != 0) {
      os << p.getSalaire() << endl;
   }
      return os << endl << endl;
   }

istream& operator >> (istream& is, Personne& p){
   string nom;
   Date dateNaissance;
   string adresse;
   string ville;
   string adresseTravail;
   string villeTravail;
   unsigned int salaire;
   
   cout << "Comment s'appelle la personne?" << endl;
   cin >> nom;
   VIDER_BUFFER;
   p.setNom(nom);
   bool dateValide;
   do{
       dateValide = true;
      cout << "Quelle est sa date de naissance" << endl;
      if (cin >> dateNaissance && dateNaissance.isValide()){
         VIDER_BUFFER;
         p.setDateNaissance(dateNaissance);
      } else {
         dateValide = false;
      }
   } while (!dateValide && cout << "Date invalide" << endl);
   
   cout << "Quelle est son adresse? (Rue)" << endl;
   getline(cin, adresse);
   p.setAdresse(adresse);
   cout << "Dans quelle ville? (NPo - Ville)" << endl;
   getline(cin, ville);
   p.setVille(ville);
   cout << "Quelle est son adresse de travail? (Rue)" << endl;
   getline(cin, adresseTravail);
   p.setAdresseTravail(adresseTravail);
   cout << "Dans quelle ville? (NPA - Ville)" << endl;
   getline(cin, villeTravail);
   p.setVilleTravail(villeTravail);
   cout << "Quel est son salaire?" << endl;
   cin >> salaire;
   VIDER_BUFFER;
   p.setSalaire(salaire);
   return is;
}
