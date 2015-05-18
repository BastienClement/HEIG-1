#include "Labo_09_Peretti_Richard_traitement.h"

void ecriture (ofstream fichier, string mot)
{
    mot += "\n";
    fichier.write((char*)&mot[0], contenu.size());
}

bool sauver (Liste liste, string nomFichier)
{
    ofstream fichier(nomFichier, ios::out);

    if (!fichier.is_open())
        return false;

    Liste.parcourir(ecriture, &fichier);

    fichier.close();
}

bool charger (Liste liste, string nomFichier)
{

}

bool chargerTrier (Liste liste, string nomFichier)
{

}
void afficher (Liste liste)
{

}
void corriger (Liste liste, string nomFichier)
{

}
