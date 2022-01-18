#include <iostream>
#include "Bambou.h"
#include "Const_stats_update.h"
#include "Constante_Thibault.h"
using namespace std;

int tab_moy_line(Bambou tabbambou[sqrt_nb_bambou], int tailley) {
	int moy = 0;
	for (int i = 0; i < tailley; i++) {
		moy += tabbambou[i].taille;
	;}
	return moy / tailley;
}

int tab_moy_column_line(Bambou tabbambou[][sqrt_nb_bambou], int taillex, int tailley) {
	int moy = 0;
	for (int i = 0; i < taillex; i++) {
		moy += tab_moy_line(tabbambou[i], tailley);
	}
	return moy / tailley;
}

int to_cut_reduce_fastest(Bambou tabbambou[][sqrt_nb_bambou], int tabx, int taby, int max_size, int& recordtaille, int& to_cutx, int& to_cuty) {
	int vitesse_max = 0;
	for (int i1 = 0; i1 < tabx; i1++) {
		for (int i2 = 0; i2 < taby; i2++) {
			if (tabbambou[i1][i2].taille > max_size and tabbambou[i1][i2].vitesse > vitesse_max) {
				tabbambou[i1][i2].vitesse = vitesse_max;
				to_cutx = i1;
				to_cuty = i2;
				if (tabbambou[i1][i2].taille > recordtaille) {
					recordtaille = tabbambou[i1][i2].taille;
				}
			}
		}
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

int min_bambou(Bambou tab[][sqrt_nb_bambou], int tabx, int taby) {
	int min = tab[0][0].taille;
	for (int i1 = 0; i1 < tabx; i1++) {
		for (int i2 = 0; i2 < taby; i2++) {
			if (tab[i1][i2].taille < min) {
				min = tab[i1][i2].taille;
			}
		}
	}
	return min;
}

int max_bambou(Bambou tab[][sqrt_nb_bambou], int tabx, int taby) {
	int max = tab[0][0].taille;
	for (int i1 = 0; i1 < tabx; i1++) {
		for (int i2 = 0; i2 < taby; i2++) {
			if (tab[i1][i2].taille > max) {
				max = tab[i1][i2].taille;
			}
		}
	}
	return max;
}