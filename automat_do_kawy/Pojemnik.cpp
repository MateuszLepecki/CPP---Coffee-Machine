#include <iostream>
using namespace std;
#include "Skladnik.h"
#include "Tryb_Klient.h"
#include "Kasa.h"
#include "Produkt.h"
#include "Pojemnik.h"

CPojemnik::CPojemnik()
{
	//string cukier = "cukier";
	for (int i = 0; i<10; i++)
	{
		tab_skladnik[i] = 0;
	}
	tab_skladnik[10] = new CSkladnik;
	tab_skladnik[10]->numer_skladnika = 11;
	tab_skladnik[10]->nazwa_skladnika = "cukier";
	tab_skladnik[10]->ilosc_skladnika = 0;
}


CPojemnik::~CPojemnik()
{
}


void CPojemnik::info()
{
	for (int i = 0; i<11; i++)
	{
		if (tab_skladnik[i] != 0)
		{
			cout << "Nr: " << tab_skladnik[i]->numer_skladnika << "\tnazwa: " << tab_skladnik[i]->nazwa_skladnika <<"\tilosc: " <<tab_skladnik[i]->ilosc_skladnika << endl;
		}
	}
}


void CPojemnik::ustawienia_wartosci()
{
	int nr_skladnika_do_uzupelnienia;
	int ilosc_uzupelnianego_skladnika;
	cout << "ktory skladnik chcesz uzupelnic?" << endl;
	cin >> nr_skladnika_do_uzupelnienia;
	cout << "na jaka ilosc ustawic skladnik?" << endl;
	cin >> ilosc_uzupelnianego_skladnika;
	tab_skladnik[nr_skladnika_do_uzupelnienia]->ilosc_skladnika = ilosc_uzupelnianego_skladnika;
	info();
}


int CPojemnik::sprawdzenie_zapasow(CTryb_Klient* klient)
{
	if (tab_skladnik[klient->wybor]->ilosc_skladnika < 1)
	{
		return 1;
	}
	else return 0;
}


void CPojemnik::dodaj_skladnik(int i, string nazwa)
{
	/*while (tab_skladnik[i] != 0)
	{
		i++;
	}*/
	tab_skladnik[i] = new CSkladnik;
	tab_skladnik[i]->numer_skladnika = i;
	tab_skladnik[i]->nazwa_skladnika = nazwa;
	cout << endl << "Podaj ilosc skladnika" << endl;
	cin >> tab_skladnik[i]->ilosc_skladnika;
}


void CPojemnik::usun_skladnik(int nr_skladnika_do_usuiecia)
{
	tab_skladnik[nr_skladnika_do_usuiecia] = 0;
}



void CPojemnik::ustawienie_ilosci_cukru()
{
	cout << endl << "Podaj poczatkow ilosc cukru" << endl;
	cin >> tab_skladnik[10]->ilosc_skladnika;
}
