#pragma once
#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include "PlikzUzytkownikami.h"

using namespace std;

class UzytkownikManager
{

	int idZalogowanegoUzytkownika;
	vector <Uzytkownik> uzytkownicy;
	PlikZUzytkownikami plikZUzytkownikami;

	int pobierzIdNowegoUzytkownika();
	bool czyIstniejeLogin(string login);
	Uzytkownik podajDaneNowegoUzytkownika();
	

public:

	void wypiszWszystkichUzytkownikow();
	void rejestracjaUzytkownika();
	void wczytajUzytkownikowZPliku();
	//int logowanieUzytkownika();
	

};

