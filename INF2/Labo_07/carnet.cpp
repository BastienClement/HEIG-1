//
// Created by Christophe on 04.05.2015.
//

#include "carnet.h"

const Personne& CarnetAdresse::operator[](const size_t i) const {
	return data[i];
}

Personne& CarnetAdresse::operator[](const size_t i) {
	return data[i];
}

void CarnetAdresse::sauver(const string& nom) const {

}
void CarnetAdresse::charger(const string& nom) {
	ifstream fichier(nom);
}
