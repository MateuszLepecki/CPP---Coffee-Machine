#include <string.>
using namespace std;

#pragma once
class CProdukt
{
public:
	CProdukt();
	~CProdukt();
	double cena;
	int numer_produktu;
	string nazwa;
	void info();
	int ilosc_produktu;
};

