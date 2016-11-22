#pragma once

#include <string>
#include <vector>

using namespace std;

vector<string> SepareChaine(string chaine)
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