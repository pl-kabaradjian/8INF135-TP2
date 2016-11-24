#include "outils.h"

void erreur(const std::string& message)
{
	cerr << "Erreur : " << message << endl;
}

vector<string> separeChaine(string chaine, int max)
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
		else if (sortie.size() < max){
			sortie.push_back(chaineTemp);
			chaineTemp = "";
		}
		else
		{
			chaineTemp += chaine[i];
		}
	}
	sortie.push_back(chaineTemp);
	return sortie;
}

void verif_argc(int argc, int nb) {
	if (argc != nb)
	{
		erreur("Mauvais nombre d'arguments");
		system("PAUSE");
		exit(-1);
	}
}

void verif_inputs(vector<string> inputs, int nb) {
	if ((int)inputs.size() != nb)
	{
		erreur("Mauvais nombre d'elements dans la chaine");
		system("PAUSE");
		exit(-1);
	}
}
