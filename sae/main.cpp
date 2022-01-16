// sae.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "struct.h"
#include "stats.cpp"
#include "update.cpp"
using namespace std;

void init_bambou(Bambou tabbambou[NBBAMBOUX][NBBAMBOUY], int taillex, int tailley) {
    for (int i1 = 0; i1 < taillex; i1++) {
        for (int i2 = 0; i2 < tailley; i2++) {
            tabbambou[i1][i2].taille = 1;
            tabbambou[i1][i2].vitesse = 1;
        }
    }
}

int debug_stat(Bambou tabbambou[NBBAMBOUX][NBBAMBOUY], int taillex, int tailley) {
    return 0;
}

int debug_update(Bambou tabbambou[NBBAMBOUX][NBBAMBOUY], int taillex, int tailley) {

    return 0;
}

int main()
{
    Panda Pand1;
    Bambou tabbambou[NBBAMBOUX][NBBAMBOUY];
    init_bambou(tabbambou, NBBAMBOUX, NBBAMBOUY);
    cout << debug_stat(tabbambou, 50, 50);
}