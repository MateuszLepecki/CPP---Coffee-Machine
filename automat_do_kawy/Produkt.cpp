#include "Produkt.h"
using namespace std;
#include<iostream>
#include <string>


CProdukt::CProdukt()
: cena(0)
, numer_produktu(0)
, ilosc_produktu(0)
{
}


CProdukt::~CProdukt()
{
}

void CProdukt::info()
{
	cout << "Nr: " << numer_produktu << "\tnazwa: " << nazwa << "\t\tcena: " << cena<<endl;
}