#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Adresat.h"
#include "MetodyPomocnicze.h"


using namespace std;

class PlikZAdresatami
{
	const string NAZWA_PLIKU_Z_ADRESATAMI;
	const string nazwaTymczasowegoPlikuTekstowego; 
	int idOstatniegoAdresata;
	bool czyPlikJestPusty(fstream& plikTekstowy);
	string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
	string pobierzLiczbe(string tekst, int pozycjaZnaku);
	Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
	int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:
	PlikZAdresatami(string nazwaPlikuZAdresatami) 
		: NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), nazwaTymczasowegoPlikuTekstowego("Adresaci_temp.txt") {
		idOstatniegoAdresata = 0;
	};

	bool dopiszAdresataDoPliku(Adresat adresat);
	vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
	int pobierzIdOstatniegoAdresata();
	bool usunAdresataZPliku(int idUsuwanegoAdresata);
	bool edytujDaneAdresataWPliku(int idEdytowanegoAdresata, Adresat& adresat, int idZalogowanegoUzytkownika);
};


#endif 
