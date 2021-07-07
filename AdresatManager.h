#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H

#include "Adresat.h"
#include "plikZAdresatami.h"
#include <vector>

using namespace std;

class AdresatManager
{

	int idOstatniegoAdresata;
	vector <Adresat> adresaci;
	PlikZAdresatami plikZAdresatami;


public:


	AdresatManager(string nazwaPlikuZAdresatami);// : plikZAdresatami(nazwaPlikuZAdresatami) {}
	void dodajAdresata(int idZalogowanegoUzytkownika);
	Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
	void wyswietlWszystkichAdresatow();
	void wyswietlDaneAdresata(Adresat adresat);
	void wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);

};


#endif // ADRESATMANAGER_H
