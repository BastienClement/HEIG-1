#include <iostream>

using namespace std;

struct Personne {
private:
	string nom;
	string prenom;
	unsigned short age;

public:
	Personne(const string& nom = "Doe", const string& prenom = "John", const unsigned short age = 30);

	const string getNom() const;
	const string getPrenom() const;
	unsigned short getAge() const;

	void setNom(const string& nom);
	void setPrenom(const string& prenom);
	void setAge(unsigned short age);

	bool operator==(const Personne& p) const;
};

Personne::Personne(const string& n, const string& p, const unsigned short a) {
	nom = n;
	prenom = p;
	age = a;
}

const string Personne::getNom() const { return nom; }
const string Personne::getPrenom() const { return prenom; }
unsigned short Personne::getAge() const { return age; }

void Personne::setNom(const string& n) { nom = n; }
void Personne::setPrenom(const string& p) { prenom = p; }
void Personne::setAge(unsigned short a) { age = a; }

bool Personne::operator==(const Personne& p) const {
	return nom == p.nom && prenom == p.prenom && age == p.age;
}

ostream& operator<<(ostream& os, const Personne& p) {
	os << p.getNom() << " " << p.getPrenom() << " (" << p.getAge() << ")";
	return os;
}

istream& operator>>(istream& is, Personne& p) {
	string str;
	cout << "Nom: ";
	getline(cin, str);
	p.setNom(str);

	cout << "Prenom: ";
	getline(cin, str);
	p.setPrenom(str);

	unsigned short age;
	do {
		cout << "Age: ";
	} while (!(cin >> age) && cout << "Erreur de saisie." << endl);
	p.setAge(age);

	return is;
}

using namespace std;
int main() {
	Personne p1("Breguet", "Guy-Michel", 50);
	Personne p2("Breguet", "Guy-Michel", 50);
	cout << (p1 == p2) << endl;
	return 0;
}