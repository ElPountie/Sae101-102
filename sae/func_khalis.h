#pragma once
#ifndef func_khalis
#define func_khalis
#include<SDL.h> 
#include<SDL_ttf.h> 
#include "config_sdl.h"
void carre(SDL_Renderer* rendu);
void place_img(SDL_Texture* monImage, SDL_Rect posImg, SDL_Renderer* rendu);
void ecrit(SDL_Renderer* rendu, TTF_Font* font);
void affiche_bambou(SDL_Renderer* rendu);
void coupe(SDL_Renderer* rendu)
#endif