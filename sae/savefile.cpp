#include <iostream>
#include <fstream>
#include <string>
#include "Constante_Thibault.h"
#include "Bambou.h"
#include "savefile.h"

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

void init_f(const char nomf[50], Bambou tabbanbou[][sqrt_nb_bambou]) {
	if (!file_exist(nomf)) {
		cout << "Nouvelle sauvegarde" << endl;
		ofstream f(nomf);
		cout << "Utiliser un tableau aleatoire ? (y/n)" << endl;
		char user;
		cin >> user;
		if (user == 'y') {
			createTemplateSaveFile(nomf);
		}
		else {
			cout << "Largeur du carre (max 49):";
			int nbbambou;
			cin >> nbbambou;
			addline(f, "Largeur carre nombre bambou : ");
			f << nbbambou;
			for (int i1 = 0; i1 < nbbambou; i1++) {
				for (int i2 = 0; i2 < nbbambou; i2++) {
					addline(f, "Taille: XXX");
					addline(f, "Vitesse: XXX");
				}
			}
		}
		f.close();
	}
	else {
		cout << "Charger une sauvegarde existante ? (y/n)" << endl;
		char user;
		cin >> user;
		if (user == 'n') {
			cout << "Utiliser un tableau aleatoire ? (y/n)" << endl;
			cin >> user;
			if (user == 'y') {
				createTemplateSaveFile(nomf);
			}
			else {
				ofstream f(nomf);
				cout << "Largeur du carre (max 49):";
				int nbbambou;
				cin >> nbbambou;
				addline(f, "Largeur carre nombre bambou : ");
				f << nbbambou;
				for (int i1 = 0; i1 < nbbambou; i1++) {
					for (int i2 = 0; i2 < nbbambou; i2++) {
						addline(f, "Taille: XXX");
						addline(f, "Vitesse: XXX");
						addline(f, "");
					}
					addline(f, "Changement de ligne");
				}
			}
		}
		else {
			int nb_cote = 0;
			loadfile(tabbanbou, nomf,nb_cote);
		}
	}
}

void loadfile(Bambou tabbanbou[][sqrt_nb_bambou], const char nomf[50],int& nb_cote) {
	if (file_readable(nomf)) {
		ifstream f(nomf);
		f.seekg(0);
		char na[30];
		f.getline(na, 30, ':');
		f >> nb_cote;
		for (int i1 = 0; i1 < nb_cote; i1++) {
			for (int i2 = 0; i2 < nb_cote; i2++) {
				f.getline(na, 30);
				f.getline(na, 30, ':');
				f >> tabbanbou[i1][i2].taille;
				f.getline(na, 30);
				f.getline(na, 30, ':');
				f >> tabbanbou[i1][i2].vitesse;
			}
		}
		f.close();
	} 
}

void createTemplateSaveFile(const char nomf[50]) {
	ofstream f(nomf);
	addline(f, "Largeur carre nombre bambou : ");
	int nbbambou = rand() % 3 + 2;
	f << nbbambou;
	for (int i1 = 0; i1 < nbbambou; i1++) {
		for (int i2 = 0; i2 < nbbambou; i2++) {
			addline(f, "Taille: ");
			f << rand() % 20;
			addline(f, "Vitesse: ");
			f << rand() % 19 + 1;
		}
		f.close();
	}
}
