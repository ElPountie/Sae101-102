#include <iostream>
#include "Bambou.h"
#include "Const_stats_update.h"
#include "Constante_Thibault.h"
#include "Stats_struct.h"
using namespace std;


float moy_bambou(Bambou tabbambou[][sqrt_nb_bambou], int taillex, int tailley) {
	int moy = 0;
	for (int i =0; i < taillex; i++) {
		for (int j = 0; j < tailley; j++)
		{
			moy += tabbambou[i][j].taille;
		}
	}
	return moy / (taillex*tailley);
}

int to_cut_reduce_fastest(Bambou tabbambou[][sqrt_nb_bambou], int tabx, int taby, int max_size, int& recordtaille, int& to_cutx, int& to_cuty) {
	int vitesse_max = 0;
	for (int i1 = 0; i1 < tabx; i1++) {
		for (int i2 = 0; i2 < taby; i2++) {
			if (tabbambou[i1][i2].taille > max_size and tabbambou[i1][i2].vitesse > vitesse_max) {
				vitesse_max = tabbambou[i1][i2].vitesse;
				to_cutx = i2;
				to_cuty = i1;
				if (tabbambou[i1][i2].taille > recordtaille) {
					recordtaille = tabbambou[i1][i2].taille;
				}
			}
		}
	}
	if (vitesse_max == 0) {
		to_cutx = to_cuty = 100;
	}
	return 0;
}

int print_bambou(Bambou tabbambou[][sqrt_nb_bambou], int tabx, int taby){
	for (int i1 = 0; i1 < tabx; i1++) {
		for (int i2 = 0; i2 < taby; i2++) {
			cout << "Bambou " << i1 << i2 << " : " << tabbambou[i1][i2].taille << " cm, " << tabbambou[i1][i2].vitesse << " cm/j" << endl;
		}
	}
	return 0;
}

float min_bambou(Bambou tab[][sqrt_nb_bambou], int tabx, int taby) {
	float min = tab[0][0].taille;
	for (int i1 = 0; i1 < tabx; i1++) {
		for (int i2 = 0; i2 < taby; i2++) {
			if (tab[i1][i2].taille < min) {
				min = tab[i1][i2].taille;
			}
		}
	}
	return min;
}

float max_bambou(Bambou tab[][sqrt_nb_bambou], int tabx, int taby) {
	float max = tab[0][0].taille;
	for (int i1 = 0; i1 < tabx; i1++) {
		for (int i2 = 0; i2 < taby; i2++) {
			if (tab[i1][i2].taille > max) {
				max = tab[i1][i2].taille;
			}
		}
	}
	return max;
}

void calcul_stats(Stats tabs[], Bambou tabb[][sqrt_nb_bambou], int tabx, int taby, int ind) {
		tabs[ind].max = max_bambou(tabb, tabx, taby);
		tabs[ind].min = min_bambou(tabb, tabx, taby);
		tabs[ind].moy = moy_bambou(tabb, tabx, taby);
}


int Sommevitesse(Bambou tab[][sqrt_nb_bambou], int tabx, int taby) {
	int sm = 0;
	for (int i1 = 0; i1 < tabx; i1++) {
		for (int i2 = 0; i2 < taby; i2++) {
			sm += tab[i1][i2].vitesse;
		}
	}
	return sm;
}