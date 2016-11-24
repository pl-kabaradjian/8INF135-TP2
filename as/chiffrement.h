#ifndef _CHIFFREMENT_H
#define _CHIFFREMENT_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string chiffrer(string cle, string chaine);
string dechiffrer(string cle, string chaine);
bool verifString(string tocheck);
bool check_and_cipher(string cle, string * chaine);

#endif