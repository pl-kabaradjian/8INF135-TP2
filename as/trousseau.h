#ifndef _TROUSSEAU_H
#define _TROUSSEAU_H

#include <string>
#include <map>

using namespace std;

class Trousseau {
	static string chemin_trousseau;
	static map<string, string>* trousseau;
public:
	static ifstream* Trousseau::ouvrir_trousseau();
	static map<string, string>* getTrousseau();
	static string* getCle(string identifiant);
	static bool existe(string id);
};

#endif