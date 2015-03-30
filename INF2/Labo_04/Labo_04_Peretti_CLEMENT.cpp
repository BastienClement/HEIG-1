/*
 -----------------------------------------------------------------------------------
 Laboratoire    : Labo_04
 Fichier        : Labo_04_Peretti_CLEMENT.cpp
 Auteur(s)      : Christophe Peretti et Bastien Clément
 Date           : 25 mars 2015

 But            : Tester les différentes structures implémentées

 Remarques(s)   : Elles fonctionnent

 Compilateur    : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include "Labo_04_Peretti_CLEMENT.h"
#include "Labo_04_Peretti_CLEMENT_QueueDynamique.h"
#include "Labo_04_Peretti_CLEMENT_QueueStatique.h"
#include "Labo_04_Peretti_CLEMENT_PileDynamique.h"
#include "Labo_04_Peretti_CLEMENT_PileStatique.h"

#define VIDER_BUFFER while (cin.get() != '\n')

int main() {

	QueueStatique  q1(5);	// Taille fixée à 5
	QueueDynamique q2;
	PileStatique   p1(5);	// Taille fixée à 5
	PileDynamique  p2;
	int            tmp;

	cout << "--------------------------------------" << endl;
	cout << "Test de la queue statique." << endl;
	cout << "Vide / Plein : " << q1.estVide() << "/" << q1.estPleine() << endl;
	cout << "Element 3 present? : " << q1.estPresent(3) << endl;
	cout << "Ajout de 7 elements dans la queue" << endl;

	for (int i = 0; i < 7; i++){
		if (q1.inserer(i)){
			cout << "Element ajoute : " << i << endl;
		} else {
			cout << "Queue pleine, element non ajoute : " << i << endl;
		}
	}
	cout << "Vide / Plein : " << q1.estVide() << "/" << q1.estPleine() << endl;
	cout << "Element 3 present? : " << q1.estPresent(3) << endl;
	cout << "Prélèvement de 7 elements de la queue" << endl;

	for (int i = 0; i < 7; i++){
		if (q1.prelever(tmp)){
			cout << "Element preleve : " << tmp << endl;
		} else {
			cout << "Queue vide, aucun element preleve." << endl;
		}
	}
	cout << "Vide / Plein : " << q1.estVide() << "/" << q1.estPleine() << endl;
	cout << "Element 3 present? : " << q1.estPresent(3) << endl;
	cout << "--------------------------------------" << endl;
	cout << "Test de la pile statique." << endl;
	cout << "Vide / Plein : " << p1.estVide() << "/" << p1.estPleine() << endl;
	cout << "Element 3 present? : " << p1.estPresent(3) << endl;
	cout << "Ajout de 7 elements dans la pile" << endl;

	for (int i = 0; i < 7; i++){
		if (p1.empiler(i)){
			cout << "Element ajoute : " << i << endl;
		} else {
			cout << "Pile pleine, element non ajoute : " << i << endl;
		}
	}
	cout << "Vide / Plein : " << p1.estVide() << "/" << p1.estPleine() << endl;
	cout << "Element 3 present? : " << p1.estPresent(3) << endl;
	cout << "Prélèvement de 7 elements de la pile" << endl;

	for (int i = 0; i < 7; i++){
		if (p1.depiler(tmp)){
			cout << "Element preleve : " << tmp << endl;
		} else {
			cout << "Pile vide, aucun element preleve." << endl;
		}
	}
	cout << "Vide / Plein : " << p1.estVide() << "/" << p1.estPleine() << endl;
	cout << "Element 3 present? : " << p1.estPresent(3) << endl;
	cout << "--------------------------------------" << endl;
	cout << "Test de la queue dynamique." << endl;
	cout << "Vide / Plein : " << q2.estVide() << "/" << q2.estPleine() << endl;
	cout << "Element 3 present? : " << q2.estPresent(3) << endl;
	cout << "Ajout de 7 elements dans la queue" << endl;

	for (int i = 0; i < 7; i++){
		if (q2.inserer(i)){
			cout << "Element ajoute : " << i << endl;
		} else {
			cout << "Queue pleine, element non ajoute : " << i << endl;
		}
	}
	cout << "Vide / Plein : " << q2.estVide() << "/" << q2.estPleine() << endl;
	cout << "Element 3 present? : " << q2.estPresent(3) << endl;
	cout << "Prélèvement de 7 elements de la queue" << endl;

	for (int i = 0; i < 7; i++){
		if (q2.prelever(tmp)){
			cout << "Element preleve : " << tmp << endl;
		} else {
			cout << "Queue vide, aucun element preleve." << endl;
		}
	}
	cout << "Vide / Plein : " << q2.estVide() << "/" << q2.estPleine() << endl;
	cout << "Element 3 present? : " << q2.estPresent(3) << endl;
	cout << "--------------------------------------" << endl;
	cout << "Test de la pile dynamique." << endl;
	cout << "Vide / Plein : " << p2.estVide() << "/" << p2.estPleine() << endl;
	cout << "Element 3 present? : " << p2.estPresent(3) << endl;
	cout << "Ajout de 7 elements dans la pile" << endl;

	for (int i = 0; i < 7; i++){
		if (p2.empiler(i)){
			cout << "Element ajoute : " << i << endl;
		} else {
			cout << "Pile pleine, element non ajoute : " << i << endl;
		}
	}
	cout << "Vide / Plein : " << p2.estVide() << "/" << p2.estPleine() << endl;
	cout << "Element 3 present? : " << p2.estPresent(3) << endl;
	cout << "Prélèvement de 7 elements de la pile" << endl;

	for (int i = 0; i < 7; i++){
		if (p2.depiler(tmp)){
			cout << "Element preleve : " << tmp << endl;
		} else {
			cout << "Pile vide, aucun element preleve." << endl;
		}
	}
	cout << "Vide / Plein : " << p2.estVide() << "/" << p2.estPleine() << endl;
	cout << "Element 3 present? : " << p2.estPresent(3) << endl;
}


