#pragma once
#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <iomanip>
using namespace std;
class PolyNom
{
public:
	PolyNom();
	PolyNom operator + (const PolyNom&) const;
	PolyNom operator - (const PolyNom&) const;
	PolyNom operator * (const PolyNom&);
	PolyNom operator = (const PolyNom&);
	PolyNom& operator +=(const PolyNom&);
	PolyNom& operator -=(const PolyNom&);
	PolyNom& operator *=(const PolyNom&);
	void enterTerms();
	void printPolyNom() const;
	int getNumOfTerms();
	int getTermExpo(int);
	int getTermCoeff(int);
	void setCoeff(int,int);
	~PolyNom();
private:
	int numOfTerms;
	int expo[100];
	int coeff[100];
	void polyNomCombine(PolyNom&);
	
};
#endif