#include <iostream>
#include "Constante_Thibault.h"
#include "fonct_thibault.h"
using namespace std;


int main() {
	int bambou[nb_bambou][nb_bambou];
	int croissance[nb_bambou][nb_bambou];
	init_bambouseraie(bambou, nb_bambou);
	vitesse_croissance(croissance, nb_bambou);
	croissance_bambouseraie(bambou,croissance, nb_bambou);
	for (int i = 0; i < nb_bambou; i++) {
		for (int j = 0; j < nb_bambou; j++) {
			cout << bambou[i][j];
		}
		cout << endl;
	}
	cout << croissance_max(bambou, croissance, nb_bambou);
	return 0;
}