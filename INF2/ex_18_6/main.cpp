#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Chaine {
private:
	size_t longueur;
	char* buffer;

	void copier(const char* chaine, size_t taille);

public:
	Chaine();
	Chaine(const char* chaine);
	Chaine(const Chaine& chaine);
	~Chaine();

	Chaine& operator=(const Chaine& chaine);
	friend ostream& operator<<(ostream&, const Chaine&);
};

void Chaine::copier(const char* chaine, size_t taille) {
	char* new_buffer = new char[taille];
	delete[] buffer;
	buffer = new_buffer;
	longueur = taille;

	if (longueur > 0)
		memcpy(buffer, chaine, longueur);
}

Chaine::Chaine() {
	copier(nullptr, 0);
}

Chaine::Chaine(const char* chaine) {
	copier(chaine, (chaine == nullptr) ? 0 : strlen(chaine));
}

Chaine::Chaine(const Chaine& chaine) {
	copier(chaine.buffer, chaine.longueur);
}

Chaine::~Chaine() {
	delete buffer;
}

Chaine& Chaine::operator=(const Chaine& chaine) {
	if (&chaine != this) {
		copier(chaine.buffer, chaine.longueur);
	}
	return *this;
}

ostream& operator<<(ostream& os, const Chaine& chaine) {
	for (size_t i = 0; i < chaine.longueur; i++) {
		os << chaine.buffer[i];
	}
	return os;
}

int main() {
	Chaine str = "Hello world";
	cout << str << endl;
	return 0;
}
