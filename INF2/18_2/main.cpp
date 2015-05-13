#include <iostream>

using namespace std;

class Point{
public:
	Point(float x, float y);
	void deplacer(float x, float y);
	float abcisse();
	float ordonnee();
private:
	float x;
	float y;
};

Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}

void Point::deplacer(float x, float y) {
	this->x += x;
	this->y += y;
}

float Point::abcisse() {
	return x;
}

float Point::ordonnee() {
	return y;
}

int main() {
	Point p(3,4);
	p.deplacer(1,1);
	cout << "(" << p.abcisse() << "," << p.ordonnee() << ")";
	return 0;
}
