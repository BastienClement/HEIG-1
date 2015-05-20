#ifndef LABO_09_PERETTI_RICHARD_TRAITEMENT_H_INCLUDED
#define LABO_09_PERETTI_RICHARD_TRAITEMENT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include "Labo_09_Peretti_Richard_liste.h"

void ecriture (std::ofstream fichier, std::string mot);
bool sauver (Liste<std::string> liste, std::string nomFichier);
bool charger (Liste<std::string> liste, std::string nomFichier);
bool chargerTrier (Liste<std::string> liste, std::string nomFichier);
void afficher (Liste<std::string> liste);
void corriger (Liste<std::string> liste, std::string nomFichier);

#endif // LABO_09_PERETTI_RICHARD_TRAITEMENT_H_INCLUDED
