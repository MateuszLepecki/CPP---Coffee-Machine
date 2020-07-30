#include <string.>
using namespace std; 
#pragma once
class CSkladnik
{
public:
	CSkladnik();
	~CSkladnik();
	int numer_skladnika;
	int ilosc_skladnika;
	string nazwa_skladnika;
	void info();
};

