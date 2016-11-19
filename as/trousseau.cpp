#include "trousseau.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

string Trousseau::chemin_trousseau = "cles.txt";

ifstream* Trousseau::ouvrir_trousseau() {
	// Ouverture du ficher d'input
	std::string input = Trousseau::chemin_trousseau;

	//ouverture en mode binaire pour eviter les problemes avec les zeros et les caracteres non affichables
	std::ifstream* instream = new ifstream(input, std::ios_base::in | std::ios_base::binary);
	if (!instream->is_open())
	{
		return nullptr;
	}
	return instream;
}

string* Trousseau::getCle(string identifiant)
{
	ifstream * trousseau = Trousseau::ouvrir_trousseau();
	if (trousseau == nullptr)
	{
		return nullptr;
	}
	string line;
	int cpt  = 0;
	while (getline(*trousseau, line)) {
		cout << "Ligne " << cpt << " : " << line << endl;
		cpt++;
	}
	string * res = new string("lol");
	return(res);
}