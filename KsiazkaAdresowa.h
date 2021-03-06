#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikManager.h"
#include "AdresatManager.h"


using namespace std;

class KsiazkaAdresowa
{
	UzytkownikManager uzytkownikManager;
	AdresatManager *adresatManager;
	const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
	KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) :
		uzytkownikManager(nazwaPlikuZUzytkownikami),
		NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
	{
		adresatManager = NULL;
	};
	~KsiazkaAdresowa() {
		delete adresatManager;
		adresatManager = NULL;
	}

	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void logowanieUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika();
	void wylogowanieUzytkownika();
	void dodajAdresata();
	void wyswietlWszystkichAdresatow();
	void wczytajAdresatowZPliku();
	bool czyUzytkownikJestZalogowany();
	void usunAdresata();
	void edytujAdresata();
	void wyszukajAdresatowPoImieniu();
	void wyszukajAdresatowPoNazwisku();

};

#endif // KSIAZKAADRESOWA_H
