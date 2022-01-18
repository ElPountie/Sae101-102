#include <iostream>
#include "Constante_Thibault.h"
#include "Bambou.h"
using namespace std;


void vitesse_croissance(Bambou croissance[][nb_bambou], int nb_bambou) {
	for (int i = 0; i < nb_bambou; i++) {
		for (int j = 0; j < nb_bambou; j++) {
			croissance[i][j].vitesse = rand() % 5;
		}
	}
}

void croissance_bambouseraie(Bambou bambou[][sqrt_nb_bambou], int nb_bambou) {
	for (int i = 0; i < nb_bambou; i++) {
		for (int j = 0; j < nb_bambou; j++) {
			if ((bambou[i][j].taille + bambou[i][j].vitesse) *5 < h_max_bambou) {
				bambou[i][j].taille = bambou[i][j].taille + bambou[i][j].vitesse;
			}
		}
	}
}

int croissance_max(Bambou bambou[][nb_bambou], Bambou croissance[][nb_bambou], int nb_bambou) {
	int Vmax = 0;
	for (int i = 0; i < nb_bambou; i++) {
		for (int j = 0; j < nb_bambou; j++) {
			if (bambou[i][j].taille > 2 * h_start_bambou) {
				if (Vmax < croissance[i][j].vitesse) {
					Vmax = croissance[i][j].vitesse;
				}
			}
		}
	}
	return Vmax;
}