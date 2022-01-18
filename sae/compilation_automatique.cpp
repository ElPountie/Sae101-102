#include <iostream>
#include "func_khalis.h"
#include "savefile.h"
#include "Bambou.h"
#include "Constante_Thibault.h"
#include "func_khalis.h"
#include "fonct_stats.h"
#include "fonct_thibault.h"

using namespace std;
/*
void start_automatic() {
	Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou];
	Panda panda;
	panda.batterie = 100;
	panda.posy = panda.posx = panda.distance = 0;
	bool running = true;

	int nb_cote = 0;
	int record_taille = 0;
	int cutx, cuty;

	init_f("Save file.txt", tab);
	loadfile(tab, "Save file.txt", nb_cote);
	init(tab, nb_cote);
	//Init image
	while (running){
		to_cut_reduce_fastest(tab, nb_cote, nb_cote, 1.45, record_taille, cutx, cuty);
		while (panda.posx != cutx && panda.posy != cuty && panda.batterie <= (panda.posx + panda.posy)){
			if (panda.batterie <= (panda.posx + panda.posy + 1)) {
				if (panda.posx == 0 && panda.posy == 0) {
					coupe(tab, 0, 0);
				}
				else if (panda.posx > 0) {
					update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3);
				}
				else if (panda.posy > 0) {
					update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 4);
				}
			}
			else if (panda.batterie == 0) {
				panda.batterie = 100;
				croissance_bambouseraie(tab, nb_bambou);
				to_cut_reduce_fastest(tab, nb_cote, nb_cote, 1.45, record_taille, cutx, cuty);
			}
			else if (panda.posx < cutx) {
				update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 1);
			}
			else if (panda.posx > cutx) {
				update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3);
			}
			else if (panda.posy < cuty) {
				update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 4);
			}
			else if (panda.posy > cuty) {
				update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 2);
			}
			else {
				cout << "Unexpected value";
			}
		}
		coupe(tab, panda.posx, panda.posy);
		croissance_bambouseraie(tab, nb_bambou);
		//Refresh image
		
		SDL_Event event;
		SDL_WaitEvent(&event);
			switch (event.type){


	}
}*/