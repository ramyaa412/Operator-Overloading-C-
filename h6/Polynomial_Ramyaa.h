#ifndef POLYNOMIAL_RAMYAA_H
#define POLYNOMIAL_RAMYAA_H
#include <iostream>
using namespace std;

class Polynomial

{
	friend std::ostream &operator<<(std::ostream &output, const Polynomial p); //Overloading Cout

public:
	int n;
	int parray[13]; //Polynomial array

	 //Constructor declaration
	Polynomial();

	void getdata();
	void setdata(int, int);

	//Operator overloading function declaration
	Polynomial operator+(Polynomial);
	Polynomial operator-(Polynomial);
	Polynomial operator*(Polynomial);
	Polynomial operator+=(Polynomial);
	Polynomial operator-=(Polynomial);
	Polynomial operator*=(Polynomial);
	void operator=(Polynomial);

	//Destructor declaration
	~Polynomial();

};




#endif