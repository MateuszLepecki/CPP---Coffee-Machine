#include "Automat.h"
#include <iostream>
using namespace std;
#include "Ekspres.h"
#include "Kasa.h"
#include "Pojemnik.h"
#include "Tryb_Klient.h"
#include "Tryb_Serwisant.h"
#include <windows.h>
#include<string>

CEkspres::CEkspres()
{
}


CEkspres::~CEkspres()
{
}


void CEkspres::przygotuj(CPojemnik* pojemnik, CTryb_Klient* klient, CProdukt* tab_produkt[10] )
{
	int czas = 10;
	cout << endl << "Czekaj, trwa przygotowywanie napoju." << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Pozostalo czasu oczekiwania: \t" << czas << endl;
		czas--;
		Sleep(1000);
	}
	cout << endl << "NAPOJ: " << pojemnik->tab_skladnik[klient->wybor]->nazwa_skladnika << " GOTOWY!!! SMACZNEGO!" << endl << endl;
	pojemnik->tab_skladnik[klient->wybor]->ilosc_skladnika = pojemnik->tab_skladnik[klient->wybor]->ilosc_skladnika - moc_napoju;
	if (wybor_cukru == 1) pojemnik->tab_skladnik[10]->ilosc_skladnika--;
}



int CEkspres::wybor_mocy_napoju()
{
	wybor:
	cout << endl << "Wybierz moc napoju 1-5" << endl;
	cin >> moc_napoju;
	if ((moc_napoju >= 1) && (moc_napoju <= 5))
	{
		return moc_napoju;
	}
	else goto wybor;
}


int CEkspres::czy_chcesz_cukier()
{
	wybor_cukru:
	cout << endl << "czy chcesz cukier: 1- tak, 0 - nie" << endl;
	cin >> wybor_cukru;
	if ((wybor_cukru >= 0) && (wybor_cukru <= 1))
	{
		return moc_napoju;
	}
	else goto wybor_cukru;
}
