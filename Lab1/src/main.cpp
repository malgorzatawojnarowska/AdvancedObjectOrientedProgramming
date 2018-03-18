#include <iostream>

#include "CProstokat.h"

using namespace std;

int main() {
	//CPunkt x;
	CPunkt a(1,1), b(2,2);
	CPunkt c(3,3), d(a);
	cout << a << b << c << d << endl;
	c = b;
	c.setX(10); c.setY(10);
	a.setX(20); a.setY(20);
	cout << a << b << c << d << endl;

	//CProstokat
	CProstokat A(a,b), B(c, d);
	cout << "A: " << A << " B: " << B << endl;
	CProstokat C(A);
	C = A + B;
	cout << "A: " << A << " B: " << B << " C: " << C << endl;

	return 0;
}
