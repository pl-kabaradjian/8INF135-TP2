#include "timestamp.h"
#include "trousseau.h"
#include <Windows.h>
#include <iostream>
#include "outils.h"
#include "chiffrement.h"
//#include <boost/thread/thread.hpp>

using namespace std;

int main(int argc, const char* argv[]){
	
	/*string id;
	cout << "Veuillez rentrer l'identifiant : ";
	cin >> id;
	string* cle = Trousseau::getCle(id);

	if (cle != nullptr) {
		cout << "Cle : " << *cle << endl;
	}*/
	string message = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz";
	string cle = "Bonjour";

	//Verification des chaines en entree
	bool ck_cle = verifString(cle);
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