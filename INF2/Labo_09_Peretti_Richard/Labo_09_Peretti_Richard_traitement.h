#ifndef LABO_09_PERETTI_RICHARD_TRAITEMENT_H_INCLUDED
#define LABO_09_PERETTI_RICHARD_TRAITEMENT_H_INCLUDED

#include <fstream>
#include "Labo_09_Peretti_Richard_liste.h"

bool sauver (Liste liste, string nomFichier);
bool charger (Liste liste, string nomFichier);
bool chargerTrier (Liste liste, string nomFichier);
void afficher (Liste liste);
void corriger (Liste liste, string nomFichier);

#endif // LABO_09_PERETTI_RICHARD_TRAITEMENT_H_INCLUDED
