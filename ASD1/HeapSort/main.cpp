//
//  quick.cpp
//
//  Created by Olivier Cuisenaire on 06.05.15.
//  Copyright (c) 2015 Olivier Cuisenaire. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

// Classe definissant une liste chainee simple
// templatee par le type d'élément que l'on y
// stocke: T

template < class T >
class SimpleList {

private:
	struct Element {
		// Eléments stockés dans la liste.

		const T data;          // données
		Element* next;   // pointeur vers l'élément suivant
	};
	typedef Element* ElementPtr;  // pointeur vers un élément
	ElementPtr head;     // pointeur vers la tête de la liste

public:
	SimpleList() : head(nullptr) {

		// constructeur d'une liste vide
	}

public:
	void push_front(T val) {

		// ajoute un élément en tête de liste

		head = new Element { val, head };
	}


private:
	ElementPtr* selectPivotLocation(ElementPtr* start, ElementPtr end) {

		// choix aléatoire du pivot.
		//
		// start est l'endroit en mémoire où est stockée l'adresse
		// du premier élément. end est l'adresse pointée par le
		// dernier élément de la liste. Par exemple, pour choisir
		// un pivot au hasard dans toute la liste, on appelle
		//
		//     selectPivotLocation(&head,nullptr);
		//
		// pour choisir un pivot au hasard dans une sous-liste, il
		// faut fournir start = &(previousElement->next) où
		// previousElement est l'élément précédent le premier
		// élément de la sous-liste, et end = lastElement->next
		// où lastElement est de dernier élément inclus dans la liste
		//
		// renvoie l'endroit en mémoire où est stockée l'adresse
		// de l'élément pivot. Cela peut soit être &head si le
		// pivot choisi est le premier élément de la liste, soit
		// &(previousElement->next) avec previousElement l'élément
		// précédent le pivot dans la liste.

		int cnt=1;
		ElementPtr* pivotLocation = start;
		ElementPtr cur = *start;
		while(cur->next != end) {
			if(!(rand()%(++cnt))) {
				pivotLocation = &(cur->next);
			}
			cur = cur->next;
		}
		return pivotLocation;
	}

private:
	void quickSort(ElementPtr* start, ElementPtr end) {

		// tri rapide récursif sur une sous liste
		//
		// voir l'explication de selectPivotLocation pour les
		// paramètres d'entrée.
		//
		// start sera modifié si le premier élément de la
		// sous liste est changé par le tri.
		//
		// doit utiliser le pivot choisi par selectPivotLocation
		// pour partitionner la sous-liste.
		//
		// doit faire croitre la sous-liste partitionnée en rattachant
		// par devant les éléments plus petits et par derrière
		// les éléments plus grand. Idéalement doit choisir au hasard
		// s'il rattache devant ou derrière les éléments égaux
		// (non testé par codecheck)
		//
		// après chaque partition et avant les appels récursifs,
		// afficher l'état de la liste en cours de tri avec
		//
		//    display(*start,pivot,end);
		//
		// où *start est un ElementPtr vers le premier élément de la
		// sous liste, pivot est un ElementPtr vers le pivot choisi
		// pour cette partition, et end est l'adresse pointée par
		// le "next" du dernier élément inclus dans la liste.

		if (*start == end || (*start)->next == end) return;

		ElementPtr* pivotPtr = selectPivotLocation(start, end);
		ElementPtr pivot = *pivotPtr;

		*pivotPtr = pivot->next;
		pivot->next = *start;
		*start = pivot;

		for (ElementPtr *curPtr = &pivot->next, cur = *curPtr; cur != end; cur = *curPtr) {
			if (cur->data < pivot->data) {
				*curPtr = cur->next;
				cur->next = *start;
				*start = cur;
			} else {
				curPtr = &cur->next;
			}
		}

		display(*start,pivot,end);

		quickSort(start, pivot);
		quickSort(&(pivot->next), end);
	}

public:
	void quickSort() {

		// effectue le tri rapide sur la liste
		//
		// doit appeler une fonction récursive mettant en oeuvre
		// le tri rapide avec les bons paramètres


		quickSort(&head, nullptr);
	}

private:
	void display(ElementPtr start, ElementPtr pivot, ElementPtr end) {

		// affiche tout la liste en entourant de crochets [] la sous
		// liste allant de start (inclus) à end (non-inclus). Entoure
		// de parenthèses () l'élément pivot
		//

		ElementPtr cur = head;
		while(cur != nullptr) {
			if(cur==start) cout << "[";
			if(cur==pivot) cout << "(";
			cout << cur->data;
			if(cur==pivot) cout << ")";
			if(cur->next==end) cout << "]";
			cout << " ";
			cur = cur->next;
		}
		cout << endl;
	}

public:
	friend std::ostream& operator<< ( std::ostream& stream,
									  const SimpleList<T>& liste) {

		// operator<< permettant d'afficher le contenu de la liste

		SimpleList<T>::Element *e = liste.head;
		while(e) {
			stream << e->data << " " ;
			e = e->next;
		}
		return stream;
	}
};

// PROGRAMME DE TEST. Crée une liste aléatoire et la trie
int main() {

	cout << "Test 1: liste d'entiers \n";

	SimpleList<int> liste1;

	const int N = 10;
	for(int i=0;i<N;++i)
		liste1.push_front(i);

	cout << "ORIGINAL: " << liste1 << endl;

	liste1.quickSort();

	cout << "SORTED:   " << liste1 << endl;

	cout << "\nTest 2: liste de chars \n";

	string testString = "MNBVCXYLKJHGFDSAPOIUZTREWQ";

	SimpleList<char> liste2;
	for(char c : testString)
		liste2.push_front(c);

	cout << "ORIGINAL: " << liste2 << endl;

	liste2.quickSort();

	cout << "SORTED:   " << liste2 << endl;
}

