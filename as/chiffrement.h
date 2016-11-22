#pragma once
#include <string>
#include <vector>
using namespace std;

string chiffrer(string cle, string chaine)
{
	string code;
	int tailleCle = cle.size();
	int tailleChaine = chaine.size();
	int indiceCle;
	int decalage;
	int valTemps;
	for (int i = 0; i < tailleChaine; i++)
	{
		//cout << "Current char : " << (unsigned int)chaine[i];

		indiceCle = i%(tailleCle);
		//cout << " Indice cle : " << indiceCle;

		decalage = (unsigned int)cle[indiceCle] - 33;
		//cout << " Decalage : " << decalage;

		valTemps = (unsigned int)chaine[i] + decalage;
		//cout << " Current char + decalage : " << valTemps;

		if (valTemps > 122)
		{
			//cout << " sup22 "<<valTemps;
			valTemps = (valTemps - 33) % 90 + 33;
		}
		code += char(valTemps);
		//cout << " Final char : " << valTemps << endl;
	}
	return code;
}

string dechiffrer(string cle, string chaine) {
	string msg;

	int tailleCle = cle.size();
	int tailleChaine = chaine.size();
	int indiceCle;
	int decalage;
	int valTemps;
	for (int i = 0; i < tailleChaine; i++)
	{
		//cout << "Current char : "<< (unsigned int)chaine[i];

		indiceCle = i % (tailleCle);
		//cout << " Indice cle : " << indiceCle;

		decalage = (unsigned int)cle[indiceCle] - 33;
		//cout << " Decalage : " << decalage;

		valTemps = (unsigned int)chaine[i] - decalage;
		//cout << " Current char + decalage : " << valTemps;

		if (valTemps < 33)
		{
			//cout << " inf33 " << valTemps;
			valTemps = valTemps + 90;
		}
		msg += char(valTemps);
		//cout << " Final char : " << valTemps << endl;
	}

	return msg;
}

bool verifString(string tocheck) {
	bool check = true;
	for (size_t i = 0; i < tocheck.size(); i++) {
		if ((int)tocheck[i] < 33 || (int)tocheck[i] > 122) check = false;
	}
	return check;
}