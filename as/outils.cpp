#include "outils.h"

void erreur(const std::string& message)
{
	cerr << "Erreur : " << message << endl;
}

void erreur_and_quit(const std::string& message)
{
	cerr << "Erreur : " << message << endl;
	system("PAUSE");
	exit(-1);
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
		else if ((int)sortie.size() < max){
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
		erreur_and_quit("Mauvais nombre d'arguments");
	}
}

void verif_inputs(vector<string> inputs, int nb) {
	if ((int)inputs.size() != nb)
	{
		erreur_and_quit("Mauvais nombre d'elements dans la chaine");
	}
}

string add_escape_chars(string chaine) {
	map<char, string> table;
	string sortie;
	table['^'] = "^^";
	table['&'] = "^&";
	table['<'] = "^<";
	table['>'] = "^>";
	//table['%'] = "%%";
	table['\\'] = "\\\\";
	table['['] = "\\[";
	table[']'] = "\\[";
	table['\"'] = "\\\"";

	//remplacement des chars
	int taille = (int)chaine.size();
	for (int i = 0 ; i < taille; i++) {
		if (table.find(chaine[i]) == table.end()) {
			sortie += chaine[i];
		}
		else {
			sortie += table[chaine[i]];
		}	
	}
	return sortie;
}