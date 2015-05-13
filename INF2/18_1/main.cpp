#include <iostream>

using namespace std;

class Point{
public:
	Point(float x, float y);
	void deplacer(float x, float y);
	void afficher() const;
private:
	float abcisse;
	float ordonnee;
};

Point::Point(float x, float y) {
	abcisse = x;
	ordonnee = y;
}

void Point::deplacer(float x, float y) {
	abcisse += x;
	ordonnee += y;
}

void Point::afficher() const {
	cout << "(" << abcisse << "," << ordonnee << ")" << endl;
}


int main() {
	Point p(3,4);
	p.deplacer(1,1);
	p.afficher();
	return 0;
}
