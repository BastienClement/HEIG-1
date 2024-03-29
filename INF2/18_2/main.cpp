#include <iostream>

using namespace std;

class Point{
public:
	Point(float x, float y);
	void deplacer(float dx, float dy);
	float abcisse() const;
	float ordonnee()const;
private:
	float x;
	float y;
};

Point::Point(float x, float y) : x(x), y(y) {}

void Point::deplacer(float dx, float dy) {
	x += dx;
	y += dy;
}

float Point::abcisse() const {
	return x;
}

float Point::ordonnee() const {
	return y;
}

int main() {
	Point p(3,4);
	p.deplacer(1,1);
	cout << "(" << p.abcisse() << "," << p.ordonnee() << ")";
	return 0;
}
