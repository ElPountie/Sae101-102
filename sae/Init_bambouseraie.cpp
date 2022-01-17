#include <iostream>
#include "Constante_Thibault.h"
using namespace std;

void init_bambouseraie(int bambou[][nb_bambou],int nb_bambou) {
	for (int i = 0; i < nb_bambou; i++) {
		for (int j = 0; j < nb_bambou; j++) {
			bambou[i][j] = h_start_bambou;
		}
	}
}