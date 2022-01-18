#include<SDL.h> 
#include<SDL_ttf.h> 
#include <iostream>
#include "func_khalis.h"
#include "savefile.h"
#include "Bambou.h"
#include "Constante_Thibault.h"
#include "constante_khalis.h"
#include "func_khalis.h"
#include "fonct_stats.h"
#include "fonct_thibault.h"

using namespace std;


int start_automatic(int nb_cote, Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou]) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "Echec à l’ouverture";
		return 1;
	}

	SDL_Window* win = SDL_CreateWindow("Titre de la fenetre",
		SDL_WINDOWPOS_CENTERED,     //pos. X: autre option: SDL_WINDOWPOS_UNDEFINED
		SDL_WINDOWPOS_CENTERED,     //pos. Y: autre option: SDL_WINDOWPOS_UNDEFINED 
		LARGEUR,                         //largeur en pixels                        
		HAUTEUR,                         //hauteur en pixels
		SDL_WINDOW_SHOWN //d’autres options (plein ecran, resizable, sans bordure...)
	);
	if (win == NULL)
		cout << "erreur ouverture fenetre";
	SDL_Renderer* rendu = SDL_CreateRenderer(
		win,  //nom de la fenêtre
		-1, //par défaut
		SDL_RENDERER_ACCELERATED); //utilisation du GPU, valeur recommandée

	TTF_Init();
	TTF_Font* font = TTF_OpenFont("calibri.ttf", 25);

	SDL_Surface* image = IMG_Load("panda.png");
	if (!image)
	{
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
		return -1;
	}

	SDL_Texture* monImage = SDL_CreateTextureFromSurface(rendu, image);
	SDL_FreeSurface(image);



	SDL_Rect posImg;
	posImg.x = 100;
	posImg.y = 100;

	SDL_QueryTexture(monImage, NULL, NULL, &posImg.w, &posImg.h);

	int Taille = sqrt_nb_bambou;
	Panda panda;
	panda.batterie = 100;
	panda.posy = panda.posx = panda.distance = 0;
	bool running = true;
	SDL_Event event;
	int record_taille = 0;
	int cutx, cuty;
	update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3);
	SDL_RenderPresent(rendu);

	while (running) {
		SDL_Delay(500);
		SDL_WaitEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;
		
		if (panda.batterie <= (panda.posx + panda.posy + 1)) {																				//Plus de batterie
			if (panda.posx > 0) {
				update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3);
			}
			else if (panda.posy > 0) {
				update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 4);
			}
			else if (panda.batterie == 1) {
				coupe(tab, panda.posx, panda.posy);
			}
			else {
				panda.batterie = 100;
				croissance_bambouseraie(tab, nb_bambou);
				to_cut_reduce_fastest(tab, nb_cote, nb_cote, 1.45, record_taille, cutx, cuty);														//Choisis le bambou à couper
			}
		}
		else if (panda.posx == cutx && panda.posy == cuty) {								//Coupe s'il est en position
			croissance_bambouseraie(tab, sqrt_nb_bambou);
			coupe(tab, panda.posx, panda.posy);
			to_cut_reduce_fastest(tab, nb_cote, nb_cote, 1.45, record_taille, cutx, cuty);														//Choisis le bambou à couper
		}
		else if (panda.posx > cutx) {														//Se dirige vers le bambou
			update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3);
		}
		else if (panda.posx < cutx) {
			update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 1);
		}
		else if (panda.posy > cuty) {
			update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 4);
		}
		else if (panda.posy < cuty) {
			update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 2);
		}
		break;
		SDL_RenderPresent(rendu);
		}
	}
	
	SDL_DestroyRenderer(rendu);

	SDL_DestroyWindow(win);

	SDL_Quit();
	return 0;
}
