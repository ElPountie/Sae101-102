#pragma once
#ifndef write_fonc_def
#define write_fonc_def
#include "Bambou.h"
#include "Constante_Thibault.h"
void init_f(const char nomf[50], Bambou tabbanbou[][sqrt_nb_bambou]);
void loadfile(Bambou tabbanbou[][sqrt_nb_bambou], const char nomf[50]);
void createTemplateSaveFile(const char nomf[50]);
#endif