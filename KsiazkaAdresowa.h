#pragma once
#include <iostream>
#include "UzytkownikManager.h"

using namespace std;

class KsiazkaAdresowa
{
	UzytkownikManager uzytkownikManager;
	string nazwaPliku;

public: 
	KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikManager(nazwaPlikuZUzytkownikami) {
	
		uzytkownikManager.wczytajUzytkownikowZPliku();
	
	};
	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();

};

