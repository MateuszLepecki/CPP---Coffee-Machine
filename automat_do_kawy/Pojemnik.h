#include <iostream>
using namespace std; 
#include "Skladnik.h"
#include "Tryb_Klient.h"
#include "Kasa.h"
#include "Produkt.h"

#pragma once
class CPojemnik
{
public:
	CPojemnik();
	~CPojemnik();
	CSkladnik* tab_skladnik[11];
	void info();
	void ustawienia_wartosci();
	int sprawdzenie_zapasow(CTryb_Klient* klient);
	void dodaj_skladnik(int, string);
	void usun_skladnik(int);
	void ustawienie_ilosci_cukru();
};

