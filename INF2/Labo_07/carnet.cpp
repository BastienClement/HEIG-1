//
// Created by Christophe on 04.05.2015.
//

#include <fstream>
#include <iostream>
#include "carnet.h"

typedef unsigned short ushort;

struct ExceptionCarnet {
	string message;
};

void CarnetAdresse::sauver(const string& nom) const {
	// Ouverture du fichier en troncation
	ofstream fichier(nom, ios::binary | ios::out | ios::trunc);

	// On s'assure d'avoir réussi
	if (!fichier.is_open())
		throw ExceptionCarnet {"Impossible d'ouvrir le fichier"};

	// Écriture de la longueur du vecteur
	ushort longueur = data.size();
	fichier.write((char*) &longueur, sizeof(longueur));

	// Écriture des personnes
	for (size_t i = 0; i < longueur; i++) {
		// Alias pour ne pas répéter data[i] trois fois
		const Personne& p = data[i];

		// On écris nom / prénom
		write_string(fichier, p.getNom());
		write_string(fichier, p.getPrenom());

		// Puis l'age
		ushort age = p.getAge();
		fichier.write((char*) &age, sizeof(age));
	}
}

void CarnetAdresse::charger(const string& nom) {
	// On vide le vecteur actuel
	data.clear();

	// Ouverture du fichier
	ifstream fichier(nom, ios::binary | ios::in);

	// On s'assure que le fichier a été ouvert avec succès
	if (!fichier.is_open())
		throw ExceptionCarnet {"Impossible d'ouvrir le fichier"};

	// Lecture de la longueur
	ushort longueur = 0;
	fichier.read((char*) &longueur, sizeof(longueur));

	// Lecture de chaque personne
	for (size_t i = 0; i < longueur; i++) {
		Personne p;

		// Lecture nom / prénom
		p.setNom(read_string(fichier));
		p.setPrenom(read_string(fichier));

		// Lecture age
		ushort age;
		fichier.read((char*) &age, sizeof(age));
		p.setAge(age);

		// On ajoute la personne dans le carnet
		data.push_back(p);
	}
};

string CarnetAdresse::read_string(istream& is) const {
	ushort longueur;
	is.read((char*) &longueur, sizeof(longueur));

	char* data = new char[longueur];
	is.read(data, longueur);
	delete data;

	return string(data, longueur);
}

void CarnetAdresse::write_string(ostream& os, const string& str) const {
	ushort longueur = str.size();
	os.write((char*) &longueur, sizeof(longueur));

	const char* data = str.data();
	os.write(data, longueur);
}

void CarnetAdresse::afficher() {
	for (size_t i = 0; i < data.size(); i++) {
		cout << data[i] << endl;
	}
}

void CarnetAdresse::ajouter(const Personne& p) {
	data.push_back(p);
}
