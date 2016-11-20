#pragma once
#include <string>
#include <map>

using namespace std;

class Trousseau {
	static string chemin_trousseau;
public:
	static ifstream* Trousseau::ouvrir_trousseau();
	static map<string, string> getTrousseau();
	static string* getCle(string identifiant);
};

