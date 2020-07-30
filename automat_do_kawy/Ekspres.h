#include "Automat.h"
#include <iostream>
using namespace std;
#include "Kasa.h"
#include "Pojemnik.h"
#include "Tryb_Klient.h"
#include "Tryb_Serwisant.h"

#pragma once
class CEkspres
{
public:
	CEkspres();
	~CEkspres();
	int moc_napoju;
	int wybor_cukru;
	void przygotuj(CPojemnik*, CTryb_Klient*, CProdukt* []);
	int wybor_mocy_napoju();
	int czy_chcesz_cukier();
};

