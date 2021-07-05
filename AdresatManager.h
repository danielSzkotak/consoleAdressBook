#pragma once
#include <iostream>
#include <vector>
#include "Adresat.h"
#include "plikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class AdresatManager
{

	int idOstatniegoAdresata;
	vector <Adresat> adresaci;
	PlikZAdresatami plikZAdresatami;
	

public:
	
	AdresatManager();
	void dodajAdresata(int idZalogowanegoUzytkownika);
	Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
	void wyswietlWszystkichAdresatow();
	void wyswietlDaneAdresata(Adresat adresat);
	
};

