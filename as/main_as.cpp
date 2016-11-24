#include "timestamp.h"
#include "trousseau.h"
#include "outils.h"
#include "chiffrement.h"
#include <Windows.h>
#include <iostream>
//#include <boost/thread/thread.hpp>

using namespace std;

string construireTicketTgs(vector<string> inputs) {
	//IDC||ADC||IDtgs||TS1||Duree1
	return string(inputs[0] + "#" + inputs[1] + "#" + inputs[2] + "#" + to_string(Timestamp::getCurrentTS()) + "#60");
}

int main(int argc, const char* argv[]){
	//lecture du trousseau
	Trousseau::getTrousseau();
	
	// Verif rapide des arguments
	verif_argc(argc,2);

	//Parsing des inputs = IDClient#Adresse#IDtgs
	vector<string> inputs = separeChaine(argv[1],2);
	verif_inputs(inputs, 3);
	
	if (Trousseau::existe(inputs[0]) && Trousseau::existe(inputs[2])) {
		string ticket = construireTicketTgs(inputs);
		cout << ticket << endl;
		if (check_and_cipher(*Trousseau::getCle(inputs[2]), &ticket))
		{
			cout << "Voici le TGT : " << ticket << endl;
		}
		else
		{
			erreur("Erreur lors du chiffrement du ticket");
		}
	}
	else
	{
		erreur("Client ou TGS inconnu");
	}

	system("PAUSE");
}

//DEBUG DU TEMPS POSIX
	//long ts;
	//while (true) {
	//	//boost::this_thread::sleep(boost::posix_time::seconds(1));
	//	ts = Timestamp::getCurrentTS();
	//	cout << ts << endl;
	//}

//UTILISATION TROUSSEAU
	/*string id;
	cout << "Veuillez rentrer l'identifiant : ";
	cin >> id;
	string* cle = Trousseau::getCle(id);

	if (cle != nullptr) {
		cout << "Cle : " << *cle << endl;
	}*/

//UTILISATION CHIFFREMENT
	//Verification des chaines en entree
	//string message = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz";
	//string cle = "Bonjour";
	/*bool ck_cle = verifString(cle);
	bool ck_msg = verifString(message);
	if (!ck_cle) {
		cout << "Error : Unauthorized char in cipher key" << endl;
	}
	if (!ck_msg) {
		cout << "Error : Unauthorized char in ciphered message" << endl;
	}
	if (ck_cle && ck_msg) {
		cout << message << endl;
		string chiffrai = chiffrer(cle, message);
		cout << chiffrai << endl;
		cout << dechiffrer(cle, chiffrai) << endl;
	}*/