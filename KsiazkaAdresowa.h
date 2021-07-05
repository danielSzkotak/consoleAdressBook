#pragma once
#include <iostream>
#include "UzytkownikManager.h"
#include "AdresatManager.h"


using namespace std;

class KsiazkaAdresowa
{
	UzytkownikManager uzytkownikManager;
	AdresatManager adresatManager;

public:
	KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikManager(nazwaPlikuZUzytkownikami) {

		uzytkownikManager.wczytajUzytkownikowZPliku();
		
	};

	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void logowanieUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika();
	void wylogowanieUzytkownika();
	void dodajAdresata();
	void wyswietlAdresatow();

};