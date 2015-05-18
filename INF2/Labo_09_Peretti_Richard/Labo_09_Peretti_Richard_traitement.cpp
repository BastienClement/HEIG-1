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

    liste.parcourir(ecriture, &fichier);

    fichier.close();
}

bool charger (Liste liste, string nomFichier)
{
    ifstream fichier (nomFichier, ios::in);
    string mot;

    if(!fichier.is_open())
        return false;

    fichier.seekg(0, ios::end);
    size_t tailleFichier = (size_t)fichier.tellg();
    fichier.seekg(0, ios::beg);

    fichier.read((char*)&mot[0], tailleFichier);

    liste.inserer(fichier.read(mot))

    fichier.close();
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
