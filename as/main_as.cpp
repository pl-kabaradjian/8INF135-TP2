#include "timestamp.h"
#include "trousseau.h"
#include <Windows.h>
#include <iostream>
#include "outils.h"
#include "chiffrement.h"
//#include <boost/thread/thread.hpp>

using namespace std;

map<string, string> trousseau;

bool Existe(string id) {
	if (trousseau.find(id) == trousseau.end())
	{
		cout << "Erreur : L'identifiant n'existe pas" << endl;
		return false;
	}
	else return true;
}

string construireTicketTgs(vector<string> inputs) {
	return string(inputs[0] + "#" + inputs[1] + "#" + inputs[2] + "#" + (char)Timestamp::getCurrentTS() + "#3600");
}

int main(int argc, const char* argv[]){
	trousseau = Trousseau::getTrousseau();
	// Verif rapide des arguments
	verif_argc(argc,2);

	//IDClient#Adresse#IDtgs
	vector<string> inputs = separeChaine(argv[1]);

	//recuperation du trousseau
	
	
	if (Existe(inputs[0]) && Existe(inputs[2])) {//TODO
		string ticket = construireTicketTgs(inputs);//TODO
		cout << chiffrer(*Trousseau::getCle(inputs[0]),ticket) << endl;//TODO
	}
	else
	{
		cout << "Client ou TGS inconnu" << endl;
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
	////Verification des chaines en entree
	//string message = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz";
	//string cle = "Bonjour";
	//bool ck_cle = verifString(cle);
	//bool ck_msg = verifString(message);
	//if (!ck_cle) {
	//	cout << "Error : Unauthorized char in cipher key" << endl;
	//}
	//if (!ck_msg) {
	//	cout << "Error : Unauthorized char in ciphered message" << endl;
	//}
	//if (ck_cle && ck_msg) {
	//	cout << message << endl;
	//	string chiffrai = chiffrer(cle, message);
	//	cout << chiffrai << endl;
	//	cout << dechiffrer(cle, chiffrai) << endl;
	//}