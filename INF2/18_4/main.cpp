#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.1415926535897;

class Point{
public:
	Point(float x, float y);
	void deplacer(float dx, float dy);
	float abcisse() const;
	float ordonnee()const;
	Point operator + (const Point& p)const;
	Point rotation(const double angle) const;
	double rho() const;
	double theta() const;
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
	Point p1(1,0);
	double angle = PI / 4;
	cout << "p1 initial : (" << p1.abcisse() << "," << p1.ordonnee() << ")" << endl;
	cout << "rho : " << p1.rho() << endl;
	cout << "theta : " << p1.theta() << endl << endl;

	for (int i = 0; i < 8; i++){
		p1 = p1.rotation((angle));

		cout << "(" << p1.abcisse() << "," << p1.ordonnee() << ")" << endl;
		cout << "rho : " << p1.rho() << endl;
		cout << "theta : " << p1.theta() << endl << endl;

	}

	return 0;
}
Point Point::operator+(const Point& p) const {
	return Point(x + p.x, y + p.y);
}
Point Point::rotation(const double angle) const {
	return Point(cos(angle) * x - sin(angle) * y, sin(angle) * x + cos(angle) * y);
}
double Point::rho() const {
	return sqrt(x * x + y * y);
}
double Point::theta() const {
	return atan(y/x) < 0 ? 2 * PI + atan(y/x) : atan(y/x);
}
