#include "trousseau.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "outils.h"

using namespace std;

string Trousseau::chemin_trousseau = "cles.txt";
map<string, string>* Trousseau::trousseau  = nullptr;

bool Trousseau::existe(string id) {
	if (Trousseau::trousseau->find(id) == Trousseau::trousseau->end())
	{
		erreur("L'identifiant n'existe pas");
		return false;
	}
	else return true;
}

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

map<string, string>* Trousseau::getTrousseau()
{
	if (Trousseau::trousseau == nullptr) {
		ifstream * stream = Trousseau::ouvrir_trousseau();
		if (stream == nullptr)
		{
			erreur("Impossible d'ouvrir le fichier de trousseau");
			return nullptr;
		}

		string line;
		std::string delim = " ";
		int cpt = 0;
		map<string, string>* map_trousseau = new map<string, string>();
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
				(*map_trousseau)[id] = mdp;
			}
		}
		Trousseau::trousseau = map_trousseau;
		return Trousseau::trousseau;
	}
	else {
		return Trousseau::trousseau;
	}
}

string* Trousseau::getCle(string identifiant)
{
	map<string, string>* trousseau = Trousseau::getTrousseau();
	if (trousseau->size() == 0) {
		erreur("Le trousseau est vide");
		return nullptr;
	}

	if (!existe(identifiant))
	{
		return nullptr;
	}
	else
	{
		string* cle = new string(trousseau->at(identifiant));
		return cle;
	}
}