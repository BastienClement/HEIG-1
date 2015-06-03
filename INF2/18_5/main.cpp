#include <iostream>


class Objet{
public:
	Objet();
	~Objet();
	unsigned int no() const;
	static unsigned int prochainNo();
	static unsigned int compteur();
private:
	static unsigned int prochainNum;
	static unsigned int nbreTotal;
	unsigned int numObjet;
};

unsigned int Objet::nbreTotal = 0;
unsigned int Objet::prochainNum = 1;

Objet::Objet() {
	numObjet = prochainNum++;
	nbreTotal++;
}

Objet::~Objet() {
	nbreTotal--;
}

unsigned int Objet::compteur() {
	return nbreTotal;
}

unsigned int Objet::prochainNo() {
	return prochainNum;
}

unsigned int Objet::no() const{
	return numObjet;
}

using namespace std;
int main() {
	Objet a, b;
	cout << "Nouvel objet a : " << a.no() << endl;
	cout << "Nouvel objet b : " << b.no() << endl;
	cout << "Nombre total : " << Objet::compteur() << endl;
	cout << "Prochain numero : " << Objet::prochainNo() << endl;
	{
		Objet c;
		cout << "Objet temporaire c : " << c.no() << endl;
		cout << "Nombre total : " << Objet::compteur() << endl;
	}
	cout << "Destruction de c..." << endl;
	cout << "Nombre total : " << Objet::compteur() << endl;

	Objet d;
	cout << "Nouvel objet d : " << d.no() << endl;
	cout << "Nombre total : " << Objet::compteur() << endl;

	return 0;
}
