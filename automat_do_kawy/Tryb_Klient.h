#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "Kasa.h"
#include "Produkt.h"

using namespace std;
#pragma once
class CTryb_Klient
{
public:
	CTryb_Klient();
	~CTryb_Klient();
	void kup(CKasa*, CProdukt* [] );
	int wybor;
};

