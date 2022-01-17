#include <iostream>
#include "Constante_Thibault.h"
using namespace std;


void vitesse_croissance(int croissance[][nb_bambou], int nb_bambou) {
	for (int i = 0; i < nb_bambou; i++) {
		for (int j = 0; j < nb_bambou; j++) {
			croissance[i][j] = rand() % 5;
		}
	}
}

void croissance_bambouseraie(int bambou[][nb_bambou], int croissance[][nb_bambou], int nb_bambou) {
	for (int i = 0; i < nb_bambou; i++) {
		for (int j = 0; j < nb_bambou; j++) {
			bambou[i][j] = bambou[i][j] + croissance[i][j] * h_start_bambou;
		}
	}
}

int croissance_max(int bambou[][nb_bambou], int croissance[][nb_bambou], int nb_bambou) {
	int Vmax = 0;
	for (int i = 0; i < nb_bambou; i++) {
		for (int j = 0; j < nb_bambou; j++) {
			if (bambou[i][j] > 2 * h_start_bambou) {
				if (Vmax < croissance[i][j]) {
					Vmax = croissance[i][j];
				}
			}
		}
	}
	return Vmax;
}