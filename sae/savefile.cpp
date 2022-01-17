#include <iostream>
#include <fstream>
#include <string>
#include "Constante_Thibault.h"
#include "Bambou.h"

using namespace std;

bool file_exist(const char nomf[50]) {
	ifstream f(nomf);
	f.close();
	return !f.fail();
}

bool file_readable(const char nomf[50]) {
	ifstream f(nomf);
	if (!f) {
		cout << "Erreur d'ouverture" << endl;
		return false;
	}
	f.close();
	return true;
}

void addline(ofstream& f, const char text[300]) {
	f << endl << text;
}

void init_f(const char nomf[50]) {
	if (!file_exist(nomf)) {
		cout << "Create save file";
		ofstream f(nomf);
		cout << "Largeur du carre (max 49):";
		int nbbambou;
		cin >> nbbambou;
		addline(f, "Largeur carre nombre bambou :XXX");
		for (int i1 = 0; i1 < nbbambou; i1++) {
			for (int i2 = 0; i2 < nbbambou; i2++) {
				addline(f, "Taille de base :XXX");
				addline(f, "Vitesse de base :XXX");
				addline(f, "");
			}
			addline(f, "Changement de ligne");
		}
		f.close();
	}
}

void loadfile(Bambou tabbanbou[][sqrt_nb_bambou], const char nomf[50]) {
	if (file_readable(nomf)) {
		ifstream f(nomf);
		int nb_cote;
		f >> nb_cote;
		for (int i1 = 0; i1 < nb_cote; i1++) {
			for (int i2 = 0; i2 < nb_cote; i2++) {
				f >> tabbanbou[i1][i2].taille;
				f >> tabbanbou[i1][i2].vitesse;
			}
		}
	}
}