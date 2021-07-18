#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include "Uzytkownik.h"
#include <string>

using namespace std;

class MetodyPomocnicze
{
public:

	static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
	static int konwersjaStringNaInt(string liczba);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
	static char wczytajZnak();
};


#endif // METODYPOMOCNICZE_H
