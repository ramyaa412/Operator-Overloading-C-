//Header files
#include "Polynomial_Ramyaa.h"
#include <iostream>
#include <iomanip>

int main()
{

	//Polynomial object declaration
	Polynomial a, b, f, g, h;

	//Getting the data from the user
	a.getdata();
	b.getdata();

	//Demostrating the << operator overloading
	cout << "\n The First Polynomial: ";
	cout << a <<endl;
	cout << "\n The Second Polynomial: ";
	cout << b <<endl;

	//Demostrating the + operator overloading
	cout << "\n Adding polynomial yields: ";
	cout << a + b << endl;

	//Demostrating the += operator overloading
	cout << "\n += the polynomial yields: ";
	cout << (a += b) << endl;

	//Demostrating the - operator overloading
	cout << "\n Subtracting the polynomial yield : ";
	cout << a - b << endl;

	//Demostrating the -= operator overloading
	cout << "\n -= the polynomials yields : ";
	cout << (a -= b) << endl;

	//Demostrating the * operator overloading
	cout << "\n Multiplying the polynomials yields: ";
	cout << a*b << endl;

	//Demostrating the *= operator overloading
	cout << "\n *= the polynomial yields: ";
	cout << (a *= b) << endl;

	return(0);
}