#include <iostream>
using namespace std;

typedef int Element;

struct DequeStatique {
private:
	Element* data;
	size_t taille;
	size_t debut;
	size_t elements = 0;

	Element& element(size_t index);

public:
	DequeStatique(size_t taille = 0);
	~DequeStatique();

	void resize(size_t taille);

	bool push_back(Element& e);
	bool pop_back(Element& e);
	bool push_front(Element& e);
	bool pop_front(Element& e);

	bool estPleine() const;
	bool estVide() const;
	bool estPresent(const Element& e) const;
};

DequeStatique::DequeStatique(size_t t) {
	data = t ? new Element[t] : nullptr;
	taille = t;
	debut = 0;
	elements = 0;
}

DequeStatique::~DequeStatique() {
	delete[] data;
}

Element& DequeStatique::element(size_t index) {
	return data[(debut + index) % taille];
}

// Redimensionnement du deque statique
void DequeStatique::resize(size_t t) {
	// Taille identique
	if (t == taille) return;

	// S'il y a trop d'éléments à copier
	if (elements > t) {
		elements = t;
	}

	// Allocation de l'espace
	Element* new_data = new Element[t];

	// Il y a des éléments à copier
	if (data) {
		for (size_t i = 0; i < elements; i++) {
			new_data[i] = element(i);
		}

		// Supression de l'ancien buffer
		delete[] data;
	}

	data = new_data;
	debut = 0;
	taille = t;
}

bool DequeStatique::push_back(Element& e) {
	if (estPleine()) return false;
	element(elements++) = e;
	return true;
}

bool DequeStatique::pop_back(Element& e) {
	if (estVide()) return false;
	e = element(--elements);
	return true;
}

bool DequeStatique::push_front(Element& e) {
	if (estPleine()) return false;
	debut = (debut == 0) ? taille - 1 : (debut - 1 % taille);
	element(0) = e;
	return true;
}

bool DequeStatique::pop_front(Element& e) {
	if (estVide()) return false;
	e = element(0);
	debut = (debut + 1) % taille;
	return true;
}

bool DequeStatique::estPleine() const {
	return elements == taille;
}

bool DequeStatique::estVide() const {
	return elements == 0;
}

bool DequeStatique::estPresent(const Element &e) const {
	for (size_t i = 0; i < elements; i++) {
		if (data[(debut + i) % taille] == e) return true;
	}
	return false;
}

// =================================================================================================

struct Noeud {
	Element valeur;
	Noeud* precedent;
	Noeud* suivant;
};

struct DequeDynamique {
private:
	Noeud* tete;
	Noeud* queue;
	size_t taille;

public:
	DequeDynamique();
	~DequeDynamique();

	bool push_back(Element& e);
	bool pop_back(Element& e);
	bool push_front(Element& e);
	bool pop_front(Element& e);

	bool estPleine() const;
	bool estVide() const;
	bool estPresent(const Element& e) const;
};

DequeDynamique::DequeDynamique() {
	tete = nullptr;
	queue = nullptr;
	taille = 0;
}

DequeDynamique::~DequeDynamique() {
	Noeud* n = tete;
	while (n) {
		n = n->suivant;
		delete n;
	}
}

// =================================================================================================

struct PileDynamique {
private:
	DequeDynamique Deque;

public:
	PileDynamique();
	~PileDynamique();
	bool empiler(const Element& e);
	bool depiler();
	bool estPleine();
	bool estVide();
	bool estPresent(const Element& e);
};

PileDynamique::PileDynamique() {
	
}

PileDynamique::~PileDynamique() {
}

PileDynamique::empiler(const Element& e) {
	Deque.push_front(e);
	}
PileDynamique::depiler() {
	Deque.pop_front();
	}
PileDynamique::estPleine() {
	
}
PileDynamique::estVide() {
	
}
PileDynamique::estPresent() {
	
}
// =================================================================================================

struct PileStatique {
private:
	DequeStatique Deque;

public:
	PileStatique(size_t taille = 50);
	~PileStatique();

	bool empiler(Element& e);
	bool depiler(Element& e);
	bool estPleine();
	bool estVide();
	bool estPresent(const Element& e);
};

PileStatique::PileStatique(size_t taille) {
	Deque.resize(taille);
}

PileStatique::~PileStatique() {
	delete[] data;
}

// =================================================================================================

struct QueueDynamique {
	bool inserer(Element& e);
	bool prelever(Element& e);
	bool estPleine();
	bool estVide();
	bool estPresent(const Element& e);
};

// =================================================================================================

struct QueueStatique {
	bool inserer(Element& e);
	bool prelever(Element& e);
	bool estPleine();
	bool estVide();
	bool estPresent(const Element& e);
};

// =================================================================================================

int main() {

}

