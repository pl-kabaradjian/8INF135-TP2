#include "timestamp.h"
#include "trousseau.h"
#include <Windows.h>
#include <iostream>
#include "outils.h"
#include "chiffrement.h"
//#include <boost/thread/thread.hpp>

using namespace std;

int main(int argc, const char* argv[]){
	// Verif rapide des arguments
	verif_argc(argc,2);

	//IDClient#Adresse#IDtgs
	vector<string> inputs = separeChaine(argv[1]);
	
	if (clientExiste(inputs[0]) && tgsExiste(inputs[2])) {//TODO
		string ticket = construireTicketTgs(inputs);//TODO
		cout << chiffrer(Trousseau::getCle(inputs[0]),ticket) << endl;//TODO
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