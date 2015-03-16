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
#include "Labo_03_Peretti_CLEMENT_personne.h"
#include "Labo_03_Peretti_CLEMENT_date.h"

using namespace std;

#define VIDER_BUFFER while (cin.get() != '\n')

Personne::Personne(string nom2, Date dateNaissance2, string adresse2,
        string adresseTravail2, unsigned int salaire2) {
   nom = nom2;
   dateNaissance = dateNaissance2;
   adresse = adresse2;
   adresseTravail = adresseTravail2;
   salaire = salaire2;
}

string Personne::getNom() const {
   return nom;
}

Date Personne::getDateNaissance() const {
   return dateNaissance;
}

string Personne::getAdresse() const {
   return adresse;
}

string Personne::getAdresseTravail() const {
   return adresseTravail;
}

unsigned int Personne::getSalaire() const {
   return salaire;
}

void Personne::setNom(const string nom2) {
   nom = nom2;
}

void Personne::setDateNaissance(const Date dateNaissance2) {
   dateNaissance = dateNaissance2;
}

void Personne::setAdresse(const string adresse2) {
   adresse = adresse2;
}

void Personne::setAdresseTravail(const string adresseTravail2) {
   adresseTravail = adresseTravail2;
}

void Personne::setSalaire(const unsigned int salaire2) {
   salaire = salaire2;
}

ostream& operator<<(ostream& os, const Personne& p) {
   if (p.getNom() != "") {
      os << p.getNom() << endl;
   }
   if (p.getAdresse() != "") {
      os << p.getAdresse() << endl;
   }
   os << p.getDateNaissance() << endl;

   if (p.getAdresseTravail() != "") {
      os << p.getAdresseTravail() << endl;
   }
   if (p.getSalaire() != 0) {
      os << p.getSalaire() << endl;
   }
      return os << endl << endl;
   }