#include "timestamp.h"
#include "trousseau.h"
#include <Windows.h>
#include <iostream>
//#include <boost/thread/thread.hpp>

using namespace std;

int main(int argc, const char* argv[]){
	long ts;
	//while (true) {
	//	//boost::this_thread::sleep(boost::posix_time::seconds(1));
	//	ts = Timestamp::getCurrentTS();
	//	cout << ts << endl;
	//}

	if (Trousseau::getCle("lol") != nullptr) {
	//cout << *Trousseau::getCle("lol");
	}
	else {
		cout << "Erreur" << endl;
	}
	//cout << argv[1] << endl;
	
	system("PAUSE");
}