#pragma once
#ifndef func_khalis
#define func_khalis
#include<SDL.h> 
#include<SDL_ttf.h> 
#include "config_sdl.h"
#include "Bambou.h"
#include "Constante_Thibault.h"
#include "Panda.h"
#include "Stats_struct.h"

void carre(SDL_Renderer* rendu,int nb_carre);
void place_img(SDL_Texture* monImage, SDL_Rect posImg, SDL_Renderer* rendu);
void ecrit(SDL_Renderer* rendu, TTF_Font* font);
void affiche_bambou(SDL_Renderer* rendu,Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou],int nb_carre);
int init(Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou],int nb_cote);
void update_movment(SDL_Rect& posImg, Panda& panda, SDL_Renderer* rendu, TTF_Font* font, Bambou tab[][sqrt_nb_bambou], SDL_Texture* monImage, int& nb_cote, int direction,int cpt_return);
void coupe(Bambou tab[sqrt_nb_bambou][sqrt_nb_bambou], int posx, int posy);
void ecrire_render(TTF_Font* font, SDL_Renderer* rendu, SDL_Color color, const char texte[100], int posx, int posy);
void batterire(SDL_Renderer* rendu, int charge);
void statistique(SDL_Renderer* rendu, Bambou tab[][sqrt_nb_bambou]);
int menue();
void background(SDL_Renderer* rendu);
void nb_coupes(SDL_Renderer* rendu, TTF_Font* font, int nb_coupe);
void message_batterie(SDL_Renderer* rendu, TTF_Font* font);
void controle(SDL_Renderer* rendu, TTF_Font* font);
void bouton(SDL_Renderer* rendu, TTF_Font* font);
#endif