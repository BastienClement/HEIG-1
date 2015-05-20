#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.1415926535897;
const double PRECISION_ZERO = 0.0000000000001;

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
	cout << setprecision(3);
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
	float x1 = cos(angle) * x - sin(angle) * y;
	float y1 = sin(angle) * x + cos(angle) * y;

	if (x1 < 0 && x1 > -PRECISION_ZERO || x1 > 0 && x1 < PRECISION_ZERO) x1 = 0;
	if (y1 < 0 && y1 > -PRECISION_ZERO || y1 > 0 && y1 < PRECISION_ZERO) y1 = 0;

	return Point(x1,y1);
}
double Point::rho() const {
	return sqrt(x * x + y * y);
}
double Point::theta() const {
	return atan(y/x) < 0 ? 2 * PI + atan(y/x) : atan(y/x);
}
