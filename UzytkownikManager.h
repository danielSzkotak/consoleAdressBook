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

class UzytkownikManager
{

	int idZalogowanegoUzytkownika;
	vector <Uzytkownik> uzytkownicy;
	PlikZUzytkownikami plikZUzytkownikami;

	int pobierzIdNowegoUzytkownika();
	bool czyIstniejeLogin(string login);
	Uzytkownik podajDaneNowegoUzytkownika();
	
	

public:
	UzytkownikManager(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
	void wypiszWszystkichUzytkownikow();
	void rejestracjaUzytkownika();
	void wczytajUzytkownikowZPliku();
	int logowanieUzytkownika();
	void ustawIdZalogowanegoUzytkownika();
	int pobierzIdZalogowanegoUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika();
	void wylogowanieUzytkownika();
	

};

