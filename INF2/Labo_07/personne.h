//
// Created by Christophe on 04.05.2015.
//

#ifndef LABO_07_PERSONNE_H
#define LABO_07_PERSONNE_H

#include <string>

using namespace std;

struct Personne {
private:
	string nom;
	string prenom;
	unsigned short age;

public:
	Personne(const string& nom = "Doe", const string& prenom = "John", const unsigned short age = 30);

	const string getNom() const;
	const string getPrenom() const;
	unsigned short getAge() const;

	void setNom(const string& nom);
	void setPrenom(const string& prenom);
	void setAge(unsigned short age);

	bool operator==(const Personne& p) const;
};
#endif //LABO_07_PERSONNE_H
