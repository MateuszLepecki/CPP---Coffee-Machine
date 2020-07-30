#include "Kasa.h"
#include <iostream>
using namespace std;

CKasa::CKasa()
: ilosc_1zl(0)
, ilosc_2zl(0)
, ilosc_5zl(0)
, ilosc_50gr(0)
{
}


CKasa::~CKasa()
{
}


void CKasa::info()
{
	cout << "posiadam (ilosc):" << endl << "50gr: " << ilosc_50gr << endl;
	cout << "1zl: " << ilosc_1zl << endl;
	cout << "2zl: " << ilosc_2zl << endl;
	cout << "5zl: " << ilosc_5zl << endl;
}


void CKasa::placenie()
{
	char placenie;
	//placenie = '1';
	while (1)//placenie!='k')
	{
		cout << endl<<"jakie monety wrzucasz?" << endl << "1. 50 gr" << endl << "2. 1 zl" << endl << "3. 2 zl" << endl << "4. 5 zl" << endl << endl;
		cin >> placenie;
		switch (placenie)
		{
		case '1':
			cout <<endl<< "wrzuciles 50gr" << endl;
			koszt = koszt - 0.5;
			ilosc_50gr++;
			break;

		case '2':
			cout <<endl<< "wrzuciles 1 zl" << endl;
			koszt = koszt - 1;
			ilosc_1zl++;
			break;

		case '3':
			cout <<endl<< "wrzuciles 2 zl" << endl;
			koszt = koszt - 2;
			ilosc_2zl++;
			break;
		case '4':
			cout <<endl<< "wrzuciles 5 zl" << endl;
			koszt = koszt - 5;
			ilosc_5zl++;
			break;
		}
		if (koszt <= 0)break;
	}
}

void CKasa::wydawanie_reszty()
{
	if (koszt < 0) cout << "Reszta do wydania"<<endl << endl;
	while (koszt != 0)
	{
		while (koszt <= -5)
		{
			cout << "oddaje 5zl" << endl;
			ilosc_5zl--;
			koszt = koszt + 5;
		}
		while (koszt <= -2)
		{
			cout << "oddaje 2zl" << endl;
			ilosc_2zl--;
			koszt = koszt + 2;
		}
		if (koszt <= -1)
		{
			cout << "oddaje 1zl" << endl;
			ilosc_1zl--;
			koszt = koszt + 1;
		}
		if (koszt <= -0.5)
		{
			cout << "oddaje 50 gr" << endl;
			ilosc_50gr--;
			koszt = koszt + 0.5;
		}
	}
}


void CKasa::ustawienia_wartosci()
{
	cout << "ile ma byc monet? " << endl;
	cout << "50gr?"  << endl;
	cin >> ilosc_50gr;
	cout << "1zl?" << endl;
	cin >> ilosc_1zl;
	cout << "2zl?" << endl;
	cin >> ilosc_2zl;
	cout << "5zl?" << endl;
	cin >> ilosc_5zl;
}


int CKasa::sprawdzenie_zapasow()
{
	if ((ilosc_50gr < 3) || (ilosc_1zl < 3) || (ilosc_2zl < 3) || (ilosc_5zl < 3))
	{
		cout << "przykro mi ale nie bede miala wydac :(" << endl;
		return 0;
	}
	else return 1;
}
