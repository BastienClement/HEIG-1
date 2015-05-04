//
// Created by Christophe on 04.05.2015.
//
#include <iostream>
#include "personne.h"

using namespace std;
Personne::Personne(const string& n, const string& p, const unsigned short a) {
	nom = n;
	prenom = p;
	age = a;
}

const string Personne::getNom() const { return nom; }
const string Personne::getPrenom() const { return prenom; }
unsigned short Personne::getAge() const { return age; }

void Personne::setNom(const string& n) { nom = n; }
void Personne::setPrenom(const string& p) { prenom = p; }
void Personne::setAge(unsigned short a) { age = a; }

bool Personne::operator==(const Personne& p) const {
	return nom == p.nom && prenom == p.prenom && age == p.age;
}

ostream& operator<<(ostream& os, const Personne& p) {
	os << p.getNom() << " " << p.getPrenom() << " (" << p.getAge() << ")";
	return os;
}

istream& operator>>(istream& is, Personne& p) {
	string str;
	cout << "Nom: ";
	getline(cin, str);
	p.setNom(str);

	cout << "Prenom: ";
	getline(cin, str);
	p.setPrenom(str);

	unsigned short age;
	do {
		cout << "Age: ";
	} while (!(cin >> age) && cout << "Erreur de saisie." << endl);
	p.setAge(age);

	return is;
}
