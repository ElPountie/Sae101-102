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

	int cpt_return = 0;

	SDL_Rect posImg;
	posImg.x = 100;
	posImg.y = 100;

	SDL_QueryTexture(monImage, NULL, NULL, &posImg.w, &posImg.h);

	Panda panda;
	panda.batterie = 100;
	panda.posy = panda.posx = panda.distance = 0;
	bool running = true;
	bool pause = false;

	const int FPS = 10;
	Uint64 start;

	SDL_Event event;
	int record_taille = 0;
	update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3,cpt_return);
	SDL_RenderPresent(rendu);
	int cutx, cuty = 100;
	int smvitesse = Sommevitesse(tab, nb_cote, nb_cote);

	SDL_EventState(SDL_MOUSEMOTION, false);
	SDL_EventState(SDL_KEYDOWN, false);
	SDL_EventState(SDL_KEYUP, false);
	SDL_EventState(SDL_MOUSEMOTION, false);
	SDL_EventState(SDL_MOUSEBUTTONDOWN, false);
	SDL_EventState(SDL_MOUSEBUTTONUP, false);

	while (running) {
		if (!pause){
			start = SDL_GetTicks64();
			to_cut_reduce_fastest(tab, nb_cote, nb_cote, Sommevitesse(tab, nb_cote, nb_cote), record_taille, cutx, cuty);
			if (cutx == 100 || cuty == 100) {
				croissance_bambouseraie(tab, nb_cote);
				affiche_bambou(rendu, tab, nb_cote);
			}
			else if (panda.batterie <= (panda.posx + panda.posy + 1)) {																				//Plus de batterie
				if (panda.posx > 0) {
					update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3, cpt_return);
					panda.batterie -= 1;
				}
				else if (panda.posy > 0) {
					update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 4, cpt_return);
					panda.batterie -= 1;
				}
				else if (panda.batterie == 1) {
					SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
					SDL_RenderClear(rendu);
					background(rendu);
					croissance_bambouseraie(tab, nb_cote);
					coupe(tab, panda.posx, panda.posy);
					place_img(monImage, posImg, rendu);
					statistique(rendu);
					carre(rendu, nb_cote);
					ecrit(rendu, font);
					affiche_bambou(rendu, tab, nb_cote);
					panda.batterie -= 1;
					batterire(rendu, panda.batterie);
				}
				else {
					panda.batterie = 100;
					croissance_bambouseraie(tab, nb_cote);														//Choisis le bambou à couper
				}
			}
			else if (panda.posx == cutx && panda.posy == cuty) {								//Coupe s'il est en position
				SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
				SDL_RenderClear(rendu);
				background(rendu);
				croissance_bambouseraie(tab, nb_cote);
				coupe(tab, panda.posx, panda.posy);
				place_img(monImage, posImg, rendu);
				statistique(rendu); 
				carre(rendu, nb_cote);
				ecrit(rendu, font);
				affiche_bambou(rendu, tab, nb_cote);
				panda.batterie -= 1;
				batterire(rendu, panda.batterie);
			}
			else if (panda.posx > cutx) {														//Se dirige vers le bambou
				update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 3,cpt_return);
				panda.batterie -= 1;
			}
			else if (panda.posx < cutx) {
				update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 1, cpt_return);
				panda.batterie -= 1;
			}
			else if (panda.posy > cuty) {
				update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 4, cpt_return);
				panda.batterie -= 1;
			}
			else if (panda.posy < cuty) {
				update_movment(posImg, panda, rendu, font, tab, monImage, nb_cote, 2, cpt_return);
				panda.batterie -= 1;
			}
		}
		if (SDL_WaitEventTimeout(&event, 100)) {
			switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
			}
		}
		SDL_RenderPresent(rendu);
	}

	SDL_DestroyRenderer(rendu);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}
