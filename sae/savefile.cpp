#include <iostream>
#include <fstream>
#include <string>
#include "Constante_Thibault.h"
#include "Bambou.h"
#include "savefile.h"

using namespace std;

void moy_x(float tab[], int taille, int x) {
	for (int i = 0; i < taille; i++) {
		tab[i] = rand() % (10 * x - 1) / 1.5 * x;
	}
}

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
				cout << "Largeur du carre (min 1, max 5):";
				int nbbambou;
				cin >> nbbambou;
				addline(f, "Largeur carre nombre bambou : ");
				f << nbbambou;
				for (int i1 = 0; i1 < nbbambou; i1++) {
					for (int i2 = 0; i2 < nbbambou; i2++) {
						addline(f, "Vitesse: XXX");
					}
				}
			}
		}
		else {
			int nb_cote = 0;
			loadfile(tabbanbou, nomf, nb_cote);
		}
	}
}

void loadfile(Bambou tabbanbou[][sqrt_nb_bambou], const char nomf[50],int& nb_cote) {
	if (file_readable(nomf)) {
		ifstream f(nomf);
		f.seekg(0);
		char na[50];
		f.getline(na, 50);
		f.getline(na, 50, ':');
		f >> nb_cote;
		if (nb_cote > 5){
			nb_cote = 5;
		}
		else if (nb_cote < 1) {
			nb_cote = 1;
		}
		int speed;
		float tab[sqrt_nb_bambou * sqrt_nb_bambou];
		for (int i1 = 0; i1 < nb_cote; i1++) {
			for (int i2 = 0; i2 < nb_cote; i2++) {
				f.getline(na, 50, ':');
				f >> speed;
				f.getline(na, 50);
				if (speed > 0 && speed < 100){
					tabbanbou[i1][i2].vitesse = speed;
					tabbanbou[i1][i2].taille = speed;
				}
				else if (nb_cote <= 3){
					createTemplateSaveFile(nomf, nb_cote);
					loadfile(tabbanbou, nomf, nb_cote);
				}
				else {
					tabbanbou[i1][i2].vitesse = rand() % 4 + 1;
					tabbanbou[i1][i2].taille = rand() % 4 + 1;
				}
			}
		}
		f.close();
	} 
}

void createTemplateSaveFile(const char nomf[50], int nbbambou) {
	ofstream f(nomf);
	addline(f, "Largeur carre nombre bambou : ");
	f << nbbambou;
	if (nbbambou < 4){
		for (int i1 = 0; i1 < nbbambou; i1++) {
			for (int i2 = 0; i2 < nbbambou; i2++) {
				int taille = rand() % 3 + 1;
				addline(f, "Vitesse: ");
				f << taille;
			}
		}
	}
	else {
		for (int i1 = 0; i1 < nbbambou; i1++) {
			for (int i2 = 0; i2 < nbbambou; i2++) {
				int taille = rand() % 2 + 1;
				addline(f, "Vitesse: ");
				f << taille;
			}
		}
	}
	f.close();
}