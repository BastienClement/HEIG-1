//
//  selection.cpp
//
//  Created by Olivier Cuisenaire on 06.05.15.
//  Copyright (c) 2015 Olivier Cuisenaire. All rights reserved.
//

#include <iostream>
using namespace std;

// Classe definissant une liste chainee simple
// templatee par le type d'élément que l'on y
// stocke: T

template < class T >
class SimpleList {

	// Elements stockés dans la liste.
	struct Element {
		const T data;          // données
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

	// selectionSort trie la liste en utilisant le tri
	// par selection.
	//
	// doit appeler
	//    cout << *this << endl;
	// après chaque permutation d'éléments.
	//
	// doit modifier les pointeurs et ne pas toucher
	// aux données.
	//
	void selectionSort() {

		// A COMPLETER

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

	liste1.selectionSort();

	cout << "SORTED:   " << liste1 << endl;

	cout << "\nTest 2: liste de chars \n";

	SimpleList<char> liste2;

	const int M = 15;
	for(int i=0;i<M;++i)
		liste2.push_front('A'+rand()%26);

	cout << "ORIGINAL: " << liste2 << endl;

	liste2.selectionSort();

	cout << "SORTED:   " << liste2 << endl;
}

