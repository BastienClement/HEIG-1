#include <iostream>

using namespace std;

class Point{
public:
	Point(float x, float y);
	void deplacer(float dx, float dy);
	float abcisse() const;
	float ordonnee()const;
	Point operator + (const Point& p) const;
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
	Point p1(3,4);
	Point p2(2,2);
	Point p3 = p1 + p2;
	cout << "(" << p3.abcisse() << "," << p3.ordonnee() << ")";
	return 0;
}
Point Point::operator+(const Point& p) const{
	return Point(x + p.x, y + p.y);
}
