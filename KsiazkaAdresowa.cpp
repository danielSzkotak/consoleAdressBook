#include "KsiazkaAdresowa.h"
#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"


void KsiazkaAdresowa::rejestracjaUzytkownika() {

	uzytkownikManager.rejestracjaUzytkownika();

}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {

	uzytkownikManager.wypiszWszystkichUzytkownikow();

}

void KsiazkaAdresowa::logowanieUzytkownika() {

	uzytkownikManager.logowanieUzytkownika();
	if (uzytkownikManager.czyUzytkownikJestZalogowany()) {

		adresatManager = new AdresatManager(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikManager.pobierzIdZalogowanegoUzytkownika());

	}

}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {

	uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();

}

void KsiazkaAdresowa::wylogowanieUzytkownika() {

	uzytkownikManager.wylogowanieUzytkownika();
	delete adresatManager;
	adresatManager = NULL;

}

void KsiazkaAdresowa::dodajAdresata() {

	adresatManager -> dodajAdresata();

}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {

	adresatManager -> wyswietlWszystkichAdresatow();

}

void KsiazkaAdresowa::wczytajAdresatowZPliku()
{
	adresatManager -> wczytajAdresatowZPliku();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany(){

	return uzytkownikManager.czyUzytkownikJestZalogowany();

}

void KsiazkaAdresowa::usunAdresata()
{
	adresatManager->usunAdresata();
}

void KsiazkaAdresowa::edytujAdresata()
{
	adresatManager->edytujAdresata();
}
