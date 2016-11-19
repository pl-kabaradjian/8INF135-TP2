#pragma once
#include <string>

using namespace std;

class Trousseau {
	static string chemin_trousseau;
public:
	static ifstream* Trousseau::ouvrir_trousseau();
	static string* getCle(string identifiant);
};

