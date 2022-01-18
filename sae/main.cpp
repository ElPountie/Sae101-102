// sae.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroi
#include <iostream>
#include "func_khalis.h"
#include "savefile.h"
#include "Bambou.h"
#include "Constante_Thibault.h"

using namespace std;

int main(int argn, char* argv[]) {
    bool fin = false;
    Bambou tabbanbou[sqrt_nb_bambou][sqrt_nb_bambou];
    init_f("Save file.txt", tabbanbou);
    while (!fin) {
        if (init(tabbanbou) == 0) {
            fin = true;
        }
    }
    return 0;
}