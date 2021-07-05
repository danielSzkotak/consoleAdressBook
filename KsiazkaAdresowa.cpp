#include "KsiazkaAdresowa.h"
#include "PlikZUzytkownikami.h"


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

void KsiazkaAdresowa::wyswietlAdresatow() {

	adresatManager.wyswietlWszystkichAdresatow();

}




