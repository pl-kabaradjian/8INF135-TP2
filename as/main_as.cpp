#include "timestamp.h"
#include "trousseau.h"
#include <Windows.h>
#include <iostream>
#include "outils.h"
#include "chiffrement.h"
//#include <boost/thread/thread.hpp>

using namespace std;

int main(int argc, const char* argv[]){
	//long ts;
	//while (true) {
	//	//boost::this_thread::sleep(boost::posix_time::seconds(1));
	//	ts = Timestamp::getCurrentTS();
	//	cout << ts << endl;
	//}
	/*string id;
	cout << "Veuillez rentrer l'identifiant : ";
	cin >> id;
	string* cle = Trousseau::getCle(id);

	if (cle != nullptr) {
		cout << "Cle : " << *cle << endl;
	}*/
	string message = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz";
	cout << message << endl;
	string chiffrai = chiffrement("bonjour", message);
	cout << chiffrai << endl;
	cout << dechiffrement("bonjour", chiffrai) << endl;

	system("PAUSE");
}