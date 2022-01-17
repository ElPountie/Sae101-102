#pragma once
#ifndef fonct_thibault
#define fonct_thibault

#include "Constante_Thibault.h"


void init_bambouseraie(int bambou[][nb_bambou], int nb_bambou);
void vitesse_croissance(int croissance[][nb_bambou], int nb_bambou);
void croissance_bambouseraie(int bambou[][nb_bambou], int croissance[][nb_bambou], int nb_bambou);
int croissance_max(int bambou[][nb_bambou], int croissance[][nb_bambou], int nb_bambou);

#endif