#include <iostream>
using namespace std;

typedef int Element;

struct ListeStatique {
private:
	Element* data;
	size_t taille;
	size_t debut;
	size_t elements = 0;

public:
	ListeStatique(size_t taille = 0);
	~ListeStatique();

	bool push_back(Element& e);
	bool pop_back(Element& e);
	bool push_front(Element& e);
	bool pop_front(Element& e);

	bool estPleine() const;
	bool estVide() const;
	bool estPresent(const Element& e) const;
	
	void resize(size_t taille);
};

ListeStatique::ListeStatique(size_t t) {
	data = t ? new Element[t] : nullptr;
	taille = t;
	debut = 0;
	elements = 0;
}

ListeStatique::~ListeStatique() {
	delete[] data;
}

// Redimensionnement de la liste statique
void ListeStatique::resize(size_t t) {
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
		for (size_t i = 0, j = debut; i < elements; i++, j++) {
			new_data[i] = data[j % taille];
		}

		// Supression de l'ancien buffer
		delete[] data;
	}

	data = new_data;
	debut = 0;
	taille = t;
}

// =================================================================================================

struct Noeud {
	Element valeur;
	Noeud* precedent;
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

	bool push_back(Element& e);
	bool pop_back(Element& e);
	bool push_front(Element& e);
	bool pop_front(Element& e);

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
	ListeDynamique liste;

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
	liste.push_front(e);
	}
PileDynamique::depiler() {
	liste.pop_front();
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
	ListeStatique liste;

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
	liste.resize(taille);
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

