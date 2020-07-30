#include "Skladnik.h"
using namespace std;
#include<iostream>


CSkladnik::CSkladnik()
: numer_skladnika(0)
, ilosc_skladnika(0)
{
}


CSkladnik::~CSkladnik()
{
}

void CSkladnik::info()
{
	cout << "Nr: " << numer_skladnika << "\tnazwa: " << nazwa_skladnika << "\tilosc: " << ilosc_skladnika << endl;
}