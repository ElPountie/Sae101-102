#pragma once
#ifndef Stats_def
#define Stats_def
#include "Constante_Thibault.h"
#include "Bambou.h"
#include "Stats_struct.h"

float moy_bambou(Bambou tabbambou[][sqrt_nb_bambou], int taillex, int tailley);
int to_cut_reduce_fastest(Bambou tabbambou[][sqrt_nb_bambou], int tabx, int taby, int max_size, int& recordtaille, int& to_cutx, int& to_cuty);
int print_bambou(Bambou tabbambou[][sqrt_nb_bambou], int tabx, int taby);
float min_bambou(Bambou tab[][sqrt_nb_bambou], int tabx, int taby);
float max_bambou(Bambou tab[][sqrt_nb_bambou], int tabx, int taby);
void calcul_stats(Stats tabs[], Bambou tabb[][sqrt_nb_bambou], int tabx, int taby, int ind);
int Sommevitesse(Bambou tab[][sqrt_nb_bambou], int tabx, int taby);
#endif