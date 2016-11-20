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

map<string, string> Trousseau::getTrousseau()
{
	ifstream * stream = Trousseau::ouvrir_trousseau();
	if (stream == nullptr)
	{
		cout << "Erreur : Impossible d'ouvrir le fichier de trousseau" << endl;
		return map<string, string>();
	}

	string line;
	std::string delim = " ";
	int cpt = 0;
	map<string, string> map_trousseau;
	string id;
	string mdp;

	while (getline(*stream, line)) 
	{
		int end = 0;
		int start = 0;
		while (end != std::string::npos)
		{
			//stockage de l'identifiant
			end = line.find(delim);
			id = line.substr(start, end);
			//stockage du mot de passe
			start = end + delim.length();
			end = line.find(delim, start);
			mdp = line.substr(start, end - start);
			//construction de la table de correspondance id<>cle
			map_trousseau[id] = mdp;
		}
	}
	return map_trousseau;
}



string* Trousseau::getCle(string identifiant)
{
	map<string, string> trousseau = Trousseau::getTrousseau();
	if (trousseau.size() == 0) {
		cout << "Erreur : Le trousseau est vide" << endl;
		return nullptr;
	}

	if (trousseau.find(identifiant) == trousseau.end())
	{
		cout << "Erreur : L'identifiant n'existe pas" << endl;
		return nullptr;
	}
	else
	{
		string* cle = new string(trousseau[identifiant]);
		return cle;
	}
}