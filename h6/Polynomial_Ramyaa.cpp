//Class definition

//Headers
#include "Polynomial_Ramyaa.h"
#include <iostream>
#include <iomanip>

//Constructor definition
Polynomial::Polynomial()
{
	for (int i = 0; i <= 12; i++)
	{
		parray[i] = 0;  //Initialising polynomial to zero
	}
	n = 0;
}

//getData definition
void Polynomial::getdata()
{
	int coeff = 0, expo = 0;

	//Getting the data from user
	cout << "\n Enter the number of polynomial terms: \n";
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cout << "\n Enter the coefficient and the exponent: \n";
		cin >> coeff >> expo;
		setdata(coeff, expo);  //Passing the data to setdata
	}

}

//setData definition
void Polynomial::setdata(int coeff, int expo)
{

	//Assigning the data to array-Polynomial
	if (expo <= 6)
		parray[expo] = coeff;
	else // limit the the degree to 6
		cout << "\n The greatest degree of a polynomial can be 6 \n";

}

//overloading the << operator
ostream &operator<<(ostream &output, const Polynomial poly)
{
	int count1 = 0;
	int count2 = 0;

	//Counting the non zero entries in the polynomial array
	for (int i = 0; i <= 12; i++)
	{
		if (poly.parray[i] != 0)
		{
			count1++;
		}
	}

	//Printing only the non-zero entries
	for (int i = 0; i <= 12; i++)
	{
		if (poly.parray[i] != 0)
		{
			count2++;
			output << poly.parray[i] << "x^" << i;
			if (count2 != count1)   //To prevent the end + from getting printed in the end
			{
				output << " + ";
			}
		}
	}
	return output;
}

//Overloading + operator
Polynomial Polynomial::operator+(Polynomial poly)
{
	Polynomial temp;
	for (int i = 0; i <= 6; i++)
	{
		temp.parray[i] = parray[i] + poly.parray[i];   //Adding individual elements of the polynomial
	}
	return temp;
}

//Overloading - operator
Polynomial Polynomial::operator-(Polynomial poly)
{
	Polynomial temp;
	for (int i = 0; i <= 6; i++)
	{
		temp.parray[i] = parray[i] - poly.parray[i];  //Subtracting the individual elements of the polynomial
	}
	return temp;
}

//Overloading * operator
Polynomial Polynomial::operator*(Polynomial poly)
{
	Polynomial temp;
	int tempmatrix[13][13];
	for (int i = 0; i <= 12; i++)
		for (int j = 0; j <= 12; j++)
			tempmatrix[i][j] = 0;

	for (int i = 0; i <= 6; i++)
		for (int j = 0; j <= 6; j++)
			tempmatrix[i][i + j] = parray[i] * poly.parray[j];  //Multiplying and assigning values to a 13x13 matrix


	for (int i = 0; i <= 12; i++)
		for (int j = 0; j <= 12; j++)
			temp.parray[i] = temp.parray[i] + tempmatrix[j][i];  //Adding along the columns to get the result
	return temp;


}

//Overloading = operator
void Polynomial::operator=(Polynomial poly)
{
	for (int i = 0; i<12; i++)
		parray[i] = poly.parray[i];    //Assigning element by element
}

//Overloading += operator
Polynomial Polynomial::operator+=(Polynomial poly)
{
	*this = *this + poly;
	return *this;
}

//Overloading -= operator
Polynomial Polynomial::operator-=(Polynomial poly)
{
	*this = *this - poly;
	return *this;
}

//Overloading *= operator
Polynomial Polynomial::operator*=(Polynomial poly)
{
	*this = *this * poly;
	return *this;
}

//Destructor definition
Polynomial::~Polynomial()
{
}