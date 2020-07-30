#include "Automat.h"
#include <iostream>
using namespace std;
#include "Kasa.h"
#include "Pojemnik.h"
#include "Tryb_Klient.h"

#pragma once
class CTryb_Serwisant
{
public:
	CTryb_Serwisant();
	~CTryb_Serwisant();
	CProdukt* tab_produkt[10];


	int kod_PIN;
	void uzupe³nij_sk³adniki(CPojemnik*);
	void pobierz_nadmiar_kasy(CKasa*);
	void uzupelnij_deficyt_kasy(CKasa*);
	void wybor_funkcji(CPojemnik*, CKasa* );

	void dodaj_produkt(CPojemnik*);
	void usun_produkt(CPojemnik*,int);
};

