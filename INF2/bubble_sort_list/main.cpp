//
//  bubble.cpp
//
//  Created by Olivier Cuisenaire on 04.05.15.
//  Copyright (c) 2015 Olivier Cuisenaire. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;

// Classe definissant une liste chainee simple
// templatee par le type d'élément que l'on y
// stocke: T

template < class T >
class SimpleList {

	// Elements stockés dans la liste.
	struct Element {
		const T data;    // données
		Element* next;   // pointeur vers l'élément suivant
	};
	typedef Element* ElementPtr;  // pointeur vers un élément

	ElementPtr head;     // pointeur vers la tête de la liste

public:

	// constructeur d'une liste vide
	SimpleList() : head(nullptr) { }

	// ajoute un élément en tête de liste
	void push_front(T val) {
		head = new Element { val, head };
	}

	void bubbleSort() {

		// A COMPLETER
		//
		// Conseil: boucler en utilisant un
		// ElementPtr* pour pouvoir modifier
		// le pointeur vers l'élément courant
		ElementPtr* courant = &head;
		ElementPtr temp;
		bool change = true;
		while (change) {
			change = false;
			while ((*courant)->next != nullptr) {
				if ((*courant)->data > (*courant)->next->data) {
					temp = *courant;
					swap(*courant,(*courant)->next);
					swap(temp->next,(*courant)->next);
					change = true;
				}
				courant = &((*courant)->next);
			}
			courant = &head;
			cout << *this << endl;
		}
	}

	// operator<< permettant d'afficher le contenu de la liste
	friend std::ostream& operator<< ( std::ostream& stream,
									  const SimpleList<T>& liste) {
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
		liste1.push_front(rand()%N);

	cout << "ORIGINAL: " << liste1 << endl;

	liste1.bubbleSort();

	cout << "SORTED:   " << liste1 << endl;

	cout << "\nTest 2: liste de chars \n";

	SimpleList<char> liste2;

	const int M = 15;
	for(int i=0;i<M;++i)
		liste2.push_front('A'+rand()%26);

	cout << "ORIGINAL: " << liste2 << endl;

	liste2.bubbleSort();

	cout << "SORTED:   " << liste2 << endl;
}
