#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H

#include "Adresat.h"
#include "plikZAdresatami.h"
#include <vector>

using namespace std;

class AdresatManager
{

	const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
	vector <Adresat> adresaci;
	PlikZAdresatami plikZAdresatami;
	Adresat podajDaneNowegoAdresata();
	void wyswietlDaneAdresata(Adresat adresat);
	int podajIdWybranegoAdresata();
	char wybierzOpcjeZMenuEdycja();

public:


	AdresatManager(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
		: plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
	{

		adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);

	};
	void dodajAdresata();
	void wyswietlWszystkichAdresatow();
	void wczytajAdresatowZPliku();
	void usunAdresata();
	void edytujAdresata();

};


#endif // ADRESATMANAGER_H
