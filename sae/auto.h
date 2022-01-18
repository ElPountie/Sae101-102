#pragma once
#ifndef auto.h
#define auto.h
#include "Bambou.h"
#include "Constante_Thibault.h"
#include "func_khalis.h"

void start_automatic(SDL_Rect& posImg, Panda& panda, SDL_Renderer* rendu, TTF_Font* font, Bambou tab[][sqrt_nb_bambou], SDL_Texture* monImage, int& nb_cote);
#endif
