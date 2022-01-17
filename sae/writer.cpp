#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool file_exist(const char nomf[50]) {
	ifstream f(nomf);
	return !f.fail();
}

void file_readable(const char nomf[50]) {
	ifstream f(nomf);
	if (!f) {
		cout << "Erreur d'ouverture" << endl;
	}
	f.close();
}

void addline(ofstream f, const char text[300]) {
	f << endl << text << endl;
}

