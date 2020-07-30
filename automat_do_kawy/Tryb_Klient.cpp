#define _CRT_SECURE_NO_WARNINGS
#include "Automat.h"
#include <iostream>
using namespace std;
#include "Kasa.h"
#include "Tryb_Klient.h"
#include "Produkt.h"

CTryb_Klient::CTryb_Klient()
{
}


CTryb_Klient::~CTryb_Klient()
{
}


void CTryb_Klient::kup(CKasa* kasa, CProdukt* tab_produkt [10] )
{

	cout << "Witaj!!" << endl << "Cennik:"  << endl;
	for (int i = 0; i < 10; i++)
	{
		if ((tab_produkt[i]) != 0)
		{
			tab_produkt[i]->info();
		}
	}
	cout << "co podac?" << endl;
start:
	cin >> wybor;
	switch (wybor)
	{
	case 0:
		cout << "do zaplaty " << tab_produkt[0]->cena<<" zl " << endl;
		kasa->koszt = tab_produkt[0]->cena;
		break;
	case 1:
		cout << "do zaplaty " << tab_produkt[1]->cena << " zl " << endl;
		kasa->koszt = tab_produkt[1]->cena;
		break;

	case 2:
		cout << "do zaplaty " << tab_produkt[2]->cena << " zl " << endl;
		kasa->koszt = tab_produkt[2]->cena;
		break;
	case 3:
		cout << "do zaplaty " << tab_produkt[3]->cena << " zl " << endl;
		kasa->koszt = tab_produkt[3]->cena;
		break;
	case 4:
		cout << "do zaplaty " << tab_produkt[4]->cena << " zl " << endl;
		kasa->koszt = tab_produkt[4]->cena;
		break;
	case 5:
		cout << "do zaplaty " << tab_produkt[5]->cena << " zl " << endl;
		kasa->koszt = tab_produkt[5]->cena;
		break;
	case 6:
		cout << "do zaplaty " << tab_produkt[6]->cena << " zl " << endl;
		kasa->koszt = tab_produkt[6]->cena;
		break;
	case 7:
		cout << "do zaplaty " << tab_produkt[7]->cena << " zl " << endl;
		kasa->koszt = tab_produkt[7]->cena;
		break;
	case 8:
		cout << "do zaplaty " << tab_produkt[8]->cena << " zl " << endl;
		kasa->koszt = tab_produkt[8]->cena;
		break;
	case 9:
		cout << "do zaplaty " << tab_produkt[9]->cena << " zl " << endl;
		kasa->koszt = tab_produkt[9]->cena;
		break;
	default:
		cout << "blad! jeszcze raz.." << endl;
		goto start;
		break;
	}

}
