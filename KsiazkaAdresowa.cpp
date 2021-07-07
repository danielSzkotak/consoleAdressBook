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

}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {

	uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();

}

void KsiazkaAdresowa::wylogowanieUzytkownika() {

	uzytkownikManager.wylogowanieUzytkownika();

}

void KsiazkaAdresowa::dodajAdresata() {

	adresatManager.dodajAdresata(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());

}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {

	adresatManager.wyswietlWszystkichAdresatow();

}

void KsiazkaAdresowa::wczytajAdresatowZPliku()
{
	adresatManager.wczytajAdresatowZPliku(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
}

