// sae.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
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