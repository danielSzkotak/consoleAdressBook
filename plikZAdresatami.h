#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{

	bool czyPlikJestPusty(fstream& plikTekstowy);
	string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);


public:
	
	void dopiszAdresataDoPliku(Adresat adresat);
	

};
