#pragma once
#ifndef Stats_def
#define Stats_def
#include "Constante_Thibault.h"
#include "Bambou.h"

int tab_moy_line(Bambou tabbambou[sqrt_nb_bambou], int tailley);
int tab_moy_column_line(Bambou tabbambou[][sqrt_nb_bambou], int taillex, int tailley);
int to_cut_reduce_fastest(Bambou tabbambou[][sqrt_nb_bambou], int tabx, int taby, int max_size, int& recordtaille, int& to_cutx, int& to_cuty);
int print_bambou(Bambou tabbambou[][sqrt_nb_bambou], int tabx, int taby);
int min_bambou(Bambou tab[][sqrt_nb_bambou], int tabx, int taby);
int max_bambou(Bambou tab[][sqrt_nb_bambou], int tabx, int taby);

#endif