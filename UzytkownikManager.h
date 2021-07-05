#pragma once
#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include "PlikzUzytkownikami.h"
#include "MetodyPomocnicze.h"
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class AdresatManager;

class UzytkownikManager
{

	vector <Uzytkownik> uzytkownicy;
	PlikZUzytkownikami plikZUzytkownikami;
	int idZalogowanegoUzytkownika;

	int pobierzIdNowegoUzytkownika();
	bool czyIstniejeLogin(string login);
	Uzytkownik podajDaneNowegoUzytkownika();
	

public:
	
	UzytkownikManager(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
	
		idZalogowanegoUzytkownika = 0;
	
	};

	void wypiszWszystkichUzytkownikow();
	void rejestracjaUzytkownika();
	void wczytajUzytkownikowZPliku();
	int logowanieUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika();
	void wylogowanieUzytkownika();

};

