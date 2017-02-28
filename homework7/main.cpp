#include "polynomial.h"
int main()
{
	PolyNom a, b, c, t;
	a.enterTerms();
	b.enterTerms();
	t = a;
	cout << "First polynomial is: \n";
	a.printPolyNom();
	cout << "Second polynomial is: \n";
	b.printPolyNom();
	cout << "\nAdding the polynomials yields: \n";
	c = a + b;
	c.printPolyNom();
	cout << "\n+= the polynomials: \n";
	a += b;
	a.printPolyNom();
	cout << "\nSubtracting the polynomials: \n";
	a = t;
	c = a - b;
	c.printPolyNom();
	cout << "\n-= the polynomials: \n";
	a -= b;
	a.printPolyNom();
	cout << "\nMultiplying the polynomials: \n";
	a = t;
	c = a * b;
	c.printPolyNom();
	cout << "\n*= the polynomials: \n";
	a *= b;
	a.printPolyNom();
	cout << endl;
	system("pause");
	return 0;
}