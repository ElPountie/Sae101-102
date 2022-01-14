#include <iostream>
#include "struct.h"
using namespace std;
const int NB_MAX_BAMBOO = 100;

int tab_moy_line(int tailley, Bambou tabbambou[]) {
	int moy = 0;
	for (int i = 0; i < tailley; i++) {
		moy += tabbambou[i].taille;
	}
	return moy / tailley;
}

int tab_moy_column_line(Bambou tabbambou[NB_MAX_BAMBOO][NB_MAX_BAMBOO], int taillex, int tailley) {
	int moy = 0;
	for (int i = 0; i < taillex; i++) {
		moy += tab_moy_line(tabbambou[i], tailley);
	}
	return moy / tailley;
}

int to_cut(Bambou* tabbambou[], int tabx, int taby, int max_size, int& to_cutx, int& to_cuty) {
	int vitesse_max = 0;
	for (int i1 = 0; i1 < tabx; i1++) {
		for (int i2 = 0; i2 < taby; i2++) {
			if (tabbambou[i1][i2].taille > max_size and tabbambou[i1][i2].vitesse > vitesse_max) {
				tabbambou[i1][i2].vitesse = vitesse_max;
				to_cutx = i1;
				to_cuty = i2;
			}
		}
	}
	return 0;
}