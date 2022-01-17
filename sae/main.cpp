// sae.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "struct.h"
#include "Constante_Thibault.h"
#include "fonct_thibault.h"
using namespace std;

int main(int argn, char* argv[]) {
    bool fin = false;
    while (!fin) {
        if (init() == 0) {
            fin = true;
        }
    }
    return 0;
}