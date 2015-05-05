//
// Created by Christophe on 04.05.2015.
//


#ifndef LABO_07_CARNET_H
#define LABO_07_CARNET_H

#include <vector>
#include "personne.h"

using namespace std;

struct CarnetAdresse {
private:
	vector<Personne> data;


public:
	Personne& operator[](const size_t i);
	const Personne& operator[](const size_t i) const;

	void sauver(const string& nom) const;
	void charger(const string& nom);
};

#endif //LABO_07_CARNET_H
