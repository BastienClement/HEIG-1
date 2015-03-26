#include <iostream>
#include "Labo_04_Peretti_CLEMENT.h"
#include "Labo_04_Peretti_CLEMENT_QueueDynamique.h"
#include "Labo_04_Peretti_CLEMENT_QueueStatique.h"
#include "Labo_04_Peretti_CLEMENT_PileDynamique.h"
#include "Labo_04_Peretti_CLEMENT_PileStatique.h"

#define VIDER_BUFFER while (cin.get() != '\n')

int main() {

	QueueStatique 		q1(5);	// Taille fixée à 10
	QueueDynamique 	q2;
	PileStatique 		p1(5);	// Taille fixée à 10
	PileDynamique 		p2;
	int 					tmp;

	cout << "--------------------------------------" << endl;
	cout << "Test de la queue statique." << endl;
	cout << "Ajout de 7 elements dans la queue" << endl;

	for (int i = 0; i < 7; i++){
		if (q1.inserer(i)){
			cout << "Element ajoute : " << i << endl;
		} else {
			cout << "Queue pleine, element non ajoute : " << i << endl;
		}
	}
	cout << "--------------------------------------" << endl;
	cout << "Prélèvement de 7 elements de la queue" << endl;

	for (int i = 0; i < 7; i++){
		if (q1.prelever(tmp)){
			cout << "Element preleve : " << tmp << endl;
		} else {
			cout << "Queue vide, aucun element preleve." << endl;
		}
	}
	cout << "--------------------------------------" << endl;
	cout << "Test de la pile statique." << endl;
	cout << "Ajout de 7 elements dans la pile" << endl;

	for (int i = 0; i < 7; i++){
		if (p1.empiler(i)){
			cout << "Element ajoute : " << i << endl;
		} else {
			cout << "Pile pleine, element non ajoute : " << i << endl;
		}
	}
	cout << "--------------------------------------" << endl;
	cout << "Prélèvement de 7 elements de la pile" << endl;

	for (int i = 0; i < 7; i++){
		if (p1.depiler(tmp)){
			cout << "Element preleve : " << tmp << endl;
		} else {
			cout << "Pile vide, aucun element preleve." << endl;
		}
	}
}


