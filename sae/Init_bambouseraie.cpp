#include <iostream>
#include "Constante_Thibault.h"
#include "struct.h"
using namespace std;

void init_bambouseraie(Bambou bambou[][nb_bambou],int nb_bambou) {
	for (int i = 0; i < sqrt(nb_bambou); i++) {
		for (int j = 0; j < sqrt(nb_bambou); j++) {
			bambou[i][j].taille = h_start_bambou;
		}
	}
}