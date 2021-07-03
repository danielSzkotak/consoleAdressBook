#include "KsiazkaAdresowa.h"
#include "PlikZUzytkownikami.h"


void KsiazkaAdresowa::rejestracjaUzytkownika() {

	uzytkownikManager.rejestracjaUzytkownika();

}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {

	uzytkownikManager.wypiszWszystkichUzytkownikow();

}

void KsiazkaAdresowa::logowanieUzytkownika() {

	uzytkownikManager.ustawIdZalogowanegoUzytkownika();

}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {

	uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();

}

void KsiazkaAdresowa::wylogowanieUzytkownika() {

	uzytkownikManager.wylogowanieUzytkownika();

}






