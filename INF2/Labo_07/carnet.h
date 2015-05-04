//
// Created by Christophe on 04.05.2015.
//


#ifndef LABO_07_CARNET_H
#define LABO_07_CARNET_H

#include <vector>
#include "personne.h"

using namespace std;

struct CarnetAdresse{
private:
	vector<Personne> carnet;


public:
	bool sauver();
	bool charger();
};

#endif //LABO_07_CARNET_H
