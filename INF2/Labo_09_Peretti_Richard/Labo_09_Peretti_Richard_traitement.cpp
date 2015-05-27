#include "Labo_09_Peretti_Richard_traitement.h"

using namespace std;

const size_t TAILLE_MAX_MOT = 50;

void ecriture (ofstream fichier, string mot)
{
    mot += "\n";
    fichier.write((char*)&mot[0], TAILLE_MAX_MOT);
}

bool sauver (Liste<string> liste, string nomFichier)
{
    ofstream fichier(nomFichier, ios::out);

    if (!fichier.is_open())
        return false;

//    liste.parcourir(ecriture, &fichier);

    fichier.close();
}

bool charger (Liste<string> liste, string nomFichier)
{
    ifstream fichier (nomFichier, ios::in);
    string mot = "a";

    if(!fichier.is_open())
        return false;

    for(size_t i = 0; fichier >> mot; i++)
        //liste.inserer(mot, i);
        cout << mot << endl;

    fichier.close();
}

bool chargerTrier (Liste<string> liste, string nomFichier)
{
    ifstream fichier (nomFichier, ios::in);
    string mot = "a";

    if(!fichier.is_open())
        return false;

    for(size_t i = 0; fichier >> mot; i++)
        //liste.inserer(mot, i);
        cout << mot << endl;

    //liste.trier("<");

    fichier.close();
}

void afficher (Liste<string> liste)
{
//\    liste.parcourir(afficherMot);
}

void afficherMot (string mot)
{
    cout << mot << endl;
}

int corriger (Liste<string> liste, string nomFichier)
{
    fstream fichier(nomFichier);

     if(!fichier.is_open())
        return false;

//    liste.parcourir(corrigerMot, motFichier)

    fichier.close();
}

void corrigerMot (string motListe, string motFichier)
{

}
