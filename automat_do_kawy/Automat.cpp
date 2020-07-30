#define _CRT_SECURE_NO_WARNINGS 
#include "Automat.h"
#include <iostream>
using namespace std;
#include "Ekspres.h"
#include "Kasa.h"
#include "Pojemnik.h"
#include "Tryb_Klient.h"
#include "Tryb_Serwisant.h"
#include "Produkt.h"

CAutomat::CAutomat()
{
	kasa = new CKasa;
	klient = new CTryb_Klient;
	ekspres = new CEkspres;
	pojemnik = new CPojemnik;
	serwisant = new CTryb_Serwisant;
	/*for (int i = 0; i<10; i++)
	{
		tab_produkt[i] = 0;
	}*/
}


CAutomat::~CAutomat()
{
}


void CAutomat::run()
{
	char kod;
	int PIN;
	while (1)
	{
		cout << endl << "Jaki tryb? s - serwisant k - klient" << endl;
		cin >> kod;
		if (kod == 's')
		{
			cout << "podaj PIN" << endl;
			cin >> PIN;
			if (PIN == serwisant->kod_PIN)
			{
				cout <<endl<< "witam serwisanta" <<endl<< endl;
				if (pojemnik->tab_skladnik[10]->ilosc_skladnika == 0)
				{
					pojemnik->ustawienie_ilosci_cukru();
				}
				serwisant->wybor_funkcji(pojemnik,kasa);
			}
			else
			{
				cout << "bledny PIN" << endl;
			}
		}
		if (kod == 'k')
		{
			if (kasa->sprawdzenie_zapasow() == 1)
			{
				int test_czy_sa_produkty = 0;
				for (int i = 0; i < 10; i++)
				{
					if (serwisant->tab_produkt[i] != 0) test_czy_sa_produkty = 1;
				}
				if (test_czy_sa_produkty == 1)
				{
					klient->kup(kasa, serwisant->tab_produkt);
					ekspres->wybor_mocy_napoju();
					ekspres->czy_chcesz_cukier();
					kasa->placenie();
					kasa->wydawanie_reszty();
					ekspres->przygotuj(pojemnik, klient, serwisant->tab_produkt);
				}
				else
				{
					cout << "najpierw dodaj produkt, aby mozna bylo cos kupic" << endl;
				}

			}
			else
			{
				cout << "Trzeba uzupelnic zapasy w kasie" << endl << endl;;
			}
		}
		
		if (kod == '/')break;
	}
}
