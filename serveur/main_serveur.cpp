#include "..\as\timestamp.h"
#include "..\as\chiffrement.h"
#include "..\as\outils.h"

const string cle = "8r$iqp!.Q";
const string nom = "V1";

int main(int argc, const char* argv[]) {
	// Verif rapide des arguments
	verif_argc(argc, 2);

	//IDClient#Adresse#IDtgs
	vector<string> inputs = separeChaine(argv[1],3);
}