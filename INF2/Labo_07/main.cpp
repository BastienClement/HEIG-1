#include <iostream>
#include "personne.h"
#include "carnet.h"

using namespace std;

int main() {
	Personne p1("Breguet", "Guy-Michel", 50);
	Personne p2;
	p2 = p1;
	p1.setAge(88);
	cout << (p1 == p2) << endl;
	return 0;
}

