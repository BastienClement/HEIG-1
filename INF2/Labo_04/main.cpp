#include <iostream>
using namespace std;

typedef int Element;

struct ListeStatique {
private:
	Element* data;
	size_t taille;
	size_t debut;
	size_t fin;

public:
	ListeStatique(size_t taille = 50);
	~ListeStatique();

	bool empiler(Element& e);
	bool depiler(Element& e);
	bool inserer(Element& e);
	bool prelever(Element& e);

	bool estPleine() const;
	bool estVide() const;
	bool estPresent(const Element& e) const;
};

ListeStatique::ListeStatique(size_t t) {
	data = new Element[t];
	taille = t;
	debut = 0;
	fin = 0;
}

ListeStatique::~ListeStatique() {
	delete[] data;
}

// =================================================================================================

struct Noeud {
	Element valeur;
	Noeud* suivant;
};

struct ListeDynamique {
private:
	Noeud* tete;
	Noeud* queue;
	size_t taille;

public:
	ListeDynamique();
	~ListeDynamique();

	bool empiler(Element& e);
	bool depiler(Element& e);
	bool inserer(Element& e);
	bool prelever(Element& e);

	bool estPleine() const;
	bool estVide() const;
	bool estPresent(const Element& e) const;
};

ListeDynamique::ListeDynamique() {
	tete = nullptr;
	queue = nullptr;
	taille = 0;
}

ListeDynamique::~ListeDynamique() {
	Noeud* n = tete;
	while (n) {
		n = n->suivant;
		delete n;
	}
}

// =================================================================================================

struct PileDynamique {
private:
	Noeud* sommet;

public:
	PileDynamique();
	~PileDynamique();
	bool empiler(Element& e);
	bool depiler(Element& e);
	bool estPleine();
	bool estVide();
	bool estPresent(const Element& e);
};

PileDynamique::PileDynamique() {
	sommet = nullptr;
}

PileDynamique::~PileDynamique() {
}

// =================================================================================================

struct PileStatique {
private:
	Element* data;
	size_t taille;

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
	data = new Element[taille];
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

