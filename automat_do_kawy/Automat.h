#pragma once
#include <iostream>
#include "Ekspres.h"
#include "Kasa.h"
#include "Pojemnik.h"
#include "Tryb_Klient.h"
#include "Tryb_Serwisant.h"
#include "Produkt.h"
using namespace std; 
class CAutomat
{
public:
	CAutomat();
	~CAutomat();
	void run();
	CEkspres *ekspres;
	CKasa* kasa;
	CPojemnik *pojemnik;
	CTryb_Serwisant *serwisant;
	CTryb_Klient* klient;
	CSkladnik* tab_skladnik [10];
	
};