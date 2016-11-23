#pragma once

#include <string>
#include <vector>

using namespace std;

vector<string> separeChaine(string chaine)
{
	vector<string> sortie;
	string chaineTemp;
	int taille = chaine.size();
	for (int i = 0; i < taille; i++)
	{
		if (chaine[i] != '#')
		{
			chaineTemp += chaine[i];
		}
		else
		{
			sortie.push_back(chaineTemp);
			chaineTemp = "";
		}
	}
	sortie.push_back(chaineTemp);
	return sortie;
}

void erreur(const std::string& message)
{
	std::cerr << "Erreur : ";
	std::cerr << message << std::endl;
}

void verif_argc(int argc, int nb) {
	if (argc != nb)
	{
		erreur("Mauvais nombre d'arguments");
		exit(-1);
	}
}