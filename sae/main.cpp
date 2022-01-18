// sae.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroi
#include <iostream>
#include "func_khalis.h"
#include "savefile.h"
#include "Bambou.h"
#include "Constante_Thibault.h"
#include "auto.h"
using namespace std;

int main(int argn, char* argv[]) {
    bool fin = false;
    Bambou tabbanbou[sqrt_nb_bambou][sqrt_nb_bambou];
    init_f("Save file.txt", tabbanbou);
    int a;
    cout << "enter valeurs .txt" << endl;
    cin >> a;
    int nb_cote;
    loadfile(tabbanbou, "Save file.txt", nb_cote);
    if (menue() == 0) {
        start_automatic(nb_cote,tabbanbou);
    }
    else{
        while (!fin) {
            if (init(tabbanbou, nb_cote) == 0) {
                fin = true;
            }
        }
    }
    return 0;
}