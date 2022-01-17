// sae.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroi
#include <iostream>
#include "Constante_Thibault.h"
#include "fonct_thibault.h"
#include "savefile.h"
using namespace std;

int main() {
    Bambou tabbanbou[sqrt_nb_bambou][sqrt_nb_bambou];
    init_f("Save file.txt");
    int a;
    cin >> a;
    loadfile(tabbanbou, "Save file.txt");
    for (int i1 = 0; i1 < sqrt_nb_bambou; i1++) {
        for (int i2 = 0; i2 < sqrt_nb_bambou; i2++) {
            cout << i1 << " " << i2 << " " << tabbanbou[i1][i2].taille << " " << tabbanbou[i1][i2].vitesse << endl;
        }
    }
    cin >> a;
    return 0;
}