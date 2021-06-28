#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami
{

	const string nazwaPlikuZUzytkownikami;
	fstream plikTekstowy;
 
	bool czyPlikJestPusty();
	string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
	Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
	PlikZUzytkownikami(string NAZWA_PLIKU_Z_UZYTKOWNIKAMI) : nazwaPlikuZUzytkownikami(NAZWA_PLIKU_Z_UZYTKOWNIKAMI) {};
	void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
	vector<Uzytkownik> wczytajUzytkownikowZPliku();



};

