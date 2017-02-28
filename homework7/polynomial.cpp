#include "polynomial.h"
PolyNom::PolyNom()
{
	for (int t = 0; t < 100; t++)
	{
		coeff[t] = 0;
		expo[t] = 0;
	}
}
void PolyNom::printPolyNom() const
{
	int start;
	bool zero = false;
	if (coeff[0])
	{
		cout << coeff[0];
		start = 1;
		zero = true;
	}
	else
	{
		if (coeff[1])
		{
			cout << coeff[1] << 'x';
			if ((expo[1] != 0) && (expo[1] != 1))
				cout << '^' << expo[1];
			zero = true;
		}

		start = 2;
	}
	for (int x = start; x < 100; x++)
	{
		if (coeff[x] != 0)
		{
			cout << showpos << coeff[x] << noshowpos << 'x';
			if ((expo[x] != 0) && (expo[x] != 1))
				cout << '^' << expo[x];
			zero = true;
		}
	}
	if (!zero)
		cout << '0';
	cout << endl;
}
PolyNom PolyNom::operator = (const PolyNom &r)
{
	expo[0] = r.expo[0];
	coeff[0] = r.coeff[0];
	for (int s = 1; (s < 100); s++)
	{
		if (r.expo[s] != 0)
		{
			expo[s] = r.expo[s];
			coeff[s] = r.coeff[s];
		}
		else
		{
			if (expo[s] == 0)
				break;
			expo[s] = 0;
			coeff[s] = 0;
		}
	}
	return *this;
}
PolyNom PolyNom::operator + (const PolyNom &r) const
{
	PolyNom temp;
	bool expoExists;
	int s;
	temp.coeff[0] = coeff[0] + r.coeff[0];
	for (s = 1; (s < 100) && (r.expo[s] != 0); s++)
	{
		temp.coeff[s] = r.coeff[s];
		temp.expo[s] = r.expo[s];
	}
	for (int x = 1; x < 100; x++)
	{
		expoExists = false;
		for (int t = 1; (t < 100) && (!expoExists); t++)
			if (expo[x] == temp.expo[t])
			{
				temp.coeff[t] += coeff[x];
				expoExists = true;
			}
		if (!expoExists)
		{
			temp.expo[s] = expo[x];
			temp.coeff[s] += coeff[x];
			s++;
		}
	}
	return temp;
}
PolyNom& PolyNom::operator +=(const PolyNom &r)
{
	*this = *this + r;
	return *this;
}
PolyNom PolyNom::operator - (const PolyNom &r) const
{
	PolyNom temp;
	bool expoExists;
	int s;
	temp.coeff[0] = coeff[0] - r.coeff[0];
	for (s = 1; (s < 100) && (expo[s] != 0); s++)
	{
		temp.coeff[s] = coeff[s];
		temp.expo[s] = expo[s];
	}
	for (int x = 1; x < 100; x++)
	{
		expoExists = false;
		for (int t = 1; (t < 100) && (!expoExists); t++)
			if (r.expo[x] == temp.expo[t])
			{
				temp.coeff[t] -= r.coeff[x];
				expoExists = true;
			}
		if (!expoExists)
		{
			temp.expo[s] = r.expo[x];
			temp.coeff[s] -= r.coeff[x];
			s++;
		}
	}
	return temp;
}
PolyNom& PolyNom::operator -=(const PolyNom &r)
{
	*this = *this - r;
	return *this;
}
PolyNom PolyNom::operator * (const PolyNom &r)
{
	PolyNom temp;
	int s = 1;
	for (int x = 0; (x < 100) && (x == 0 || coeff[x] != 0); x++)
		for (int y = 0; (y < 100) && (y == 0 || r.coeff[y] != 0); y++)
			if ((expo[x] == 0) && (r.expo[y] == 0))
				temp.coeff[0] += coeff[x] * r.coeff[y];
			else
			{
				temp.coeff[s] = (coeff[x] * r.coeff[y]);
				temp.expo[s] = expo[x] + r.expo[y];
				s++;
				
			}
	polyNomCombine(temp);
	return temp;
}
void PolyNom::polyNomCombine(PolyNom &w)
{
	PolyNom temp = w;
	int exp;
	for (int x = 0; x < 100; x++)
	{
		w.coeff[x] = 0;
		w.expo[x] = 0;
	}
	for (int x = 1; x < 100; x++)
	{
		exp = temp.expo[x];
		for (int y = x + 1; y < 100; y++)
			if (exp == temp.expo[y])
			{
				temp.coeff[x] += temp.coeff[y];
				temp.expo[y] = 0;
				temp.coeff[y] = 0;
			}
	}
	w = temp;
	
}
PolyNom& PolyNom::operator *=(const PolyNom &r)
{
	*this = *this * r;
	return *this;
}
void PolyNom::enterTerms()
{
	bool found = false;
	int c, e, term;
	cout << "\nEnter number of polynomial terms: ";
	cin >> numOfTerms;
	for (int n = 1; n <= numOfTerms; n++)
	{
		cout << "\nEnter a coefficient: ";
		cin >> c;
		cout << "Enter exponent: ";
		cin >> e;
		if (c != 0)
		{
			if (e == 0)
			{
				coeff[0] += c;
				continue;
			}
			for (term = 1; (term < 100) && (coeff[term] != 0); term++)
				if (e == expo[term])
				{
					coeff[term] += c;
					expo[term] = e;
					found = true;
				}
			if (!found)
			{
				coeff[term] += c;
				expo[term] = e;
			}
		}
	}
}
int PolyNom::getNumOfTerms()
{
	return numOfTerms;
}
int PolyNom::getTermExpo(int term)
{
	return expo[term];
}
int PolyNom::getTermCoeff(int term)
{
	return coeff[term];
}
void PolyNom::setCoeff(int term,int c)
{
	if (coeff[term] == 0)
		cout << "No term at this here, can't set term." << endl;
	else
		coeff[term] = c;
}
PolyNom::~PolyNom()
{
}