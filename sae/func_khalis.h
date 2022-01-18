#pragma once
#ifndef func_khalis
#define func_khalis
#include<SDL.h> 
#include<SDL_ttf.h> 
#include "config_sdl.h"
#include "Bambou.h"
#include "Constante_Thibault.h"
#include "Panda.h"

void carre(SDL_Renderer* rendu,int nb_carre);
void place_img(SDL_Texture* monImage, SDL_Rect posImg, SDL_Renderer* rendu);
void ecrit(SDL_Renderer* rendu, TTF_Font* font);
void affiche_bambou(SDL_Renderer* rendu,Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou],int nb_carre);
void menue(SDL_Renderer* rendu, TTF_Font* font);
int init(Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou],int nb_cote);
void update_movment(SDL_Rect& posImg, Panda& panda, SDL_Renderer* rendu, TTF_Font* font, Bambou tab[][sqrt_nb_bambou], SDL_Texture* monImage, int& nb_cote, int direction);
void coupe(Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou], int posx, int posy);
#endif