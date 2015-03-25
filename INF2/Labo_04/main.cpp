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

	bool push_back(Element e);
	bool pop_back(Element& e);

	bool push_front(Element e);
	bool pop_front(Element& e);

	bool estPlein() const;
	bool estVide() const;
	bool estPresent(Element e) const;
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

	// S'il y a trop d'Ã©lÃ©ments Ã  copier
	if (elements > t) {
		elements = t;
	}

	// Allocation de l'espace
	Element* new_data = new Element[t];

	// Il y a des Ã©lÃ©ments Ã  copier
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

bool DequeStatique::push_back(Element e) {
	if (estPlein()) return false;
	element(elements++) = e;
	return true;
}

bool DequeStatique::pop_back(Element& e) {
	if (estVide()) return false;
	e = element(--elements);
	return true;
}

bool DequeStatique::push_front(Element e) {
	if (estPlein()) return false;
	debut = (debut == 0 ? taille : debut) - 1;
	element(0) = e;
	elements++;
	return true;
}

bool DequeStatique::pop_front(Element& e) {
	if (estVide()) return false;
	e = element(0);
	elements--;
	debut = (debut + 1) % taille;
	return true;
}

bool DequeStatique::estPlein() const {
	return elements == taille;
}

bool DequeStatique::estVide() const {
	return elements == 0;
}

bool DequeStatique::estPresent(Element e) const {
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
	size_t elements;

public:
	DequeDynamique();
	~DequeDynamique();

	bool push_back(Element e);
	bool pop_back(Element& e);
	bool push_front(Element e);
	bool pop_front(Element& e);

	bool estPlein() const;
	bool estVide() const;
	bool estPresent(Element e) const;
};

DequeDynamique::DequeDynamique() {
	tete = nullptr;
	queue = nullptr;
	elements = 0;
}

DequeDynamique::~DequeDynamique() {
	Noeud* n = tete;
	while (n) {
		n = n->suivant;
		delete n;
	}
}

bool DequeDynamique::push_back(Element e) {
	// CrÃ©ation d'un nouveau noeud
	Noeud* n = new(nothrow) Noeud;
	if (!n) return false;

	// Initialisation du noeud avec un pointeur
	// vers la queue actuelle et aucun noeud suivant
	*n = { e, queue, nullptr };

	if (estVide()) {
		// Si le deque est vide, la nouvelle queue
		// est aussi la tÃªte
		tete = n;
	} else {
		// Sinon on dÃ©fini la nouvelle queue comme Ã©tant
		// le noeud suivant de la queue actuelle
		queue->suivant = n;
	}

	// Mise Ã  jour de la queue
	queue = n;

	// IncrÃ©mentation du nombre d'Ã©lÃ©ment
	elements++;

	return true;
}

bool DequeDynamique::pop_back(Element& e) {
	if (estVide()) return false;

	// Pointeur sur le dernier Ã©lÃ©ment
	Noeud* q = queue;
	e = q->valeur;

	// On recule la queue d'un Ã©lÃ©ment
	queue = queue->precedent;

	if (queue) {
		queue->suivant = nullptr;
	} else {
		tete = nullptr;
	}

	// DÃ©crÃ©mentation du nombre d'Ã©lÃ©ments dans le deque
	elements--;

	return true;
}

bool DequeDynamique::push_front(Element e) {
	// CrÃ©ation d'un nouveau noeud
	Noeud* n = new(nothrow) Noeud;
	if (!n) return false;

	// Initialisation du noeud avec un pointeur
	// vers la tÃªte actuelle et aucun noeud prÃ©cÃ©dent
	*n = { e, nullptr, tete };

	if (estVide()) {
		// Si le deque est vide, la nouvelle tÃªte
		// est aussi la queue
		queue = n;
	} else {
		// Sinon on dÃ©fini la nouvelle tÃªte comme Ã©tant
		// le noeud prÃ©cÃ©dent de la tÃªte actuelle
		tete->precedent = n;
	}

	// Mise Ã  jour de la tÃªte
	tete = n;

	// Mise Ã  jour du nombre d'Ã©lÃ©ments
	elements++;

	return true;
}

bool DequeDynamique::pop_front(Element& e) {
	if (estVide()) return false;

	// Pointeur sur le premier Ã©lÃ©ment
	Noeud* t = tete;
	e = t->valeur;

	// On avant la tÃªte d'un Ã©lÃ©ment
	tete = tete->suivant;

	if (tete) {
		tete->precedent = nullptr;
	} else {
		queue = nullptr;
	}

	// DÃ©crÃ©mentation du nombre d'Ã©lÃ©ments dans le deque
	elements--;

	return true;
}

bool DequeDynamique::estPlein() const {
	// Un deque dynamique n'est jamais plein
	return false;
}

bool DequeDynamique::estVide() const {
	return elements == 0;
}

bool DequeDynamique::estPresent(Element e) const {
	Noeud* n = tete;
	while (n) {
		if (n->valeur == e) return true;
		n = n->suivant;
	}
	return false;
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

