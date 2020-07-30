#pragma once
class CKasa
{
public:
	CKasa();
	~CKasa();
	int ilosc_1zl;
	int ilosc_2zl;
	int ilosc_5zl;
	int ilosc_50gr;
	double koszt;
	void info();
	void placenie();
	void wydawanie_reszty();
	void ustawienia_wartosci();
	int sprawdzenie_zapasow();
};

