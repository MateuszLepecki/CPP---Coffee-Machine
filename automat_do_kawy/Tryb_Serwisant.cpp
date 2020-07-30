#include "Automat.h"
#include <iostream>
using namespace std;
#include "Ekspres.h"
#include "Kasa.h"
#include "Pojemnik.h"
#include "Tryb_Klient.h"
#include "Tryb_Serwisant.h"

CTryb_Serwisant::CTryb_Serwisant()
: kod_PIN(4325)
{
	for (int i = 0; i<10; i++)
	{
		tab_produkt[i] = 0;
	}
}


CTryb_Serwisant::~CTryb_Serwisant()
{
}


void CTryb_Serwisant::uzupe³nij_sk³adniki(CPojemnik* pojemnik)
{
	int test_czy_sa_produkty=0;
	for (int i = 0; i < 10; i++)
	{
		if (tab_produkt[i] != 0) test_czy_sa_produkty=1;
	}
	if (test_czy_sa_produkty==1)
	{
		pojemnik->info();
		pojemnik->ustawienia_wartosci();
		cout << endl << "uzupelniono skladnik" << endl << endl;
	}
	else
	{
		cout << "najpierw dodaj produkt, aby uzupelnic jego skladniki" << endl;
	}
}


void CTryb_Serwisant::pobierz_nadmiar_kasy(CKasa* kasa)
{
	kasa->info();
	if (kasa->ilosc_50gr >= 200) kasa->ilosc_50gr = 100;
	if (kasa->ilosc_1zl >= 200) kasa->ilosc_1zl = 100;
	if (kasa->ilosc_2zl >= 200) kasa->ilosc_2zl = 100;
	if (kasa->ilosc_5zl >= 200) kasa->ilosc_5zl = 100;
}


void CTryb_Serwisant::uzupelnij_deficyt_kasy(CKasa* kasa)
{
	kasa->info();
	kasa->ustawienia_wartosci();
}


void CTryb_Serwisant::wybor_funkcji(CPojemnik* pojemnik, CKasa* kasa)
{
	char wybor;
	int usun;
	wybor = '1';
	while (wybor != 'k')
	{
		cout << "1. Uzupelnij skladniki" << endl;
		cout << "2. Pobierz nadmiar kasy" << endl;
		cout << "3. uzupelnij deficyt kasy" << endl;
		cout << "4. dodaj nowy produkt" << endl;
		cout << "5. usun produkt" << endl;
		cout << "6. wyswietl menu, info kasa i pojemnik" << endl;
		cout << "k - koniec" << endl;
		start:
		cin >> wybor;
		switch (wybor)
		{
		case '1':
			uzupe³nij_sk³adniki(pojemnik);
			pojemnik->info();
			break;

		case '2':
			pobierz_nadmiar_kasy(kasa);
			cout <<endl<< "pobrano ewentualny nadmiar kasy" << endl<<endl;
			kasa->info();
			break;
		case '3':
			uzupelnij_deficyt_kasy(kasa);
			cout <<endl<< "uzupelniono deficyt kasy" <<endl<< endl;
			kasa->info();
			break;
		case '4':
			dodaj_produkt(pojemnik);
			break;
		case '5':
			cout << "Ktory produkt usunac?" << endl;
			cin >> usun;
			usun_produkt(pojemnik, usun);
			cout << "Produkt zostal usuniety" << endl;
			break;
		case '6':
			cout << endl << "PRODUKTY:" << endl;
			for (int i = 0; i < 10; i++)
			{
				if ((tab_produkt[i]) != 0)
				{
					tab_produkt[i]->info();
				}
			}
			cout << endl << "SKLADNIKI:" << endl;
			pojemnik->info();
			cout << endl<<endl << "KASA:" << endl;
			kasa->info();
			cout << endl;
			break;
		case 'k':
			wybor = 'k';
			break;
		default:
			cout << "blad! jeszcze raz.." << endl;
			goto start;
			break;
		}
	}
}


void CTryb_Serwisant::dodaj_produkt(CPojemnik* pojemnik)
{
	int i = 0;
	while (tab_produkt[i] != 0)
	{
		i++;
	}
	tab_produkt[i] = new CProdukt;
	tab_produkt[i]->numer_produktu = i;
	cout << endl << "Podaj nazwe nowego produktu" << endl;
	cin >> tab_produkt[i]->nazwa;
	cout << endl << "Podaj cene nowego produktu" << endl;
	cin >> tab_produkt[i]->cena;
	tab_produkt[i]->info();
	pojemnik->dodaj_skladnik(i,tab_produkt[i]->nazwa);
	pojemnik->tab_skladnik[i]->info();
	
}


void CTryb_Serwisant::usun_produkt(CPojemnik* pojemnik,int nr_produktu_do_usuniecia)
{
	tab_produkt[nr_produktu_do_usuniecia] = 0;
	pojemnik->usun_skladnik(nr_produktu_do_usuniecia);
}
