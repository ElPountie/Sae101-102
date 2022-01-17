// sae.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "func_khalis.h"

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