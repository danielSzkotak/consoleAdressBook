#pragma once
#include <iostream>
#include "UzytkownikManager.h"

using namespace std;

class KsiazkaAdresowa
{
	UzytkownikManager uzytkownikManager;

public: 
	KsiazkaAdresowa();
	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();

};

