#include <iostream>

using namespace std;

const int nb_bambou = 12;
const int h_start_bambou = 1;
const int h_max_bambou = 5 * h_start_bambou;

void init_bambouseraie(int bambou[][nb_bambou], int nb_bambou) {
	for (int i = 0; i < nb_bambou; i++) {
		for (int j = 0; j < nb_bambou; j++) {
			bambou[i][j] = h_start_bambou;
		}
	}
}

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
	return 0;
}