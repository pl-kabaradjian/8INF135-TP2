#ifndef _OUTILS_H
#define _OUTILS_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

void erreur(const std::string& message);
vector<string> separeChaine(string chaine, int max);
void verif_argc(int argc, int nb);
void verif_inputs(vector<string> inputs, int nb);

#endif