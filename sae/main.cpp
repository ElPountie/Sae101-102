// sae.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "struct.h"
#include "stats.cpp"
#include "update.cpp"
using namespace std;

const int NBBAMBOUX = 50;
const int NBBAMBOUY = 50;

int debug_stat(Bambou* tabbambou[], int taillex, int tailley) {
    update_bambou_size(tabbambou, taillex, tailley);
    cout << tab_moy_column_line(tabbambou, taillex, tailley);
    print_bambou(&tabbambou[49], taillex, tailley);
    return 0;
}

int debug_update(Bambou* tabbambou[], int taillex, int tailley) {

    return 0;
}

int main()
{
    Bambou* tabbambou[NBBAMBOUX][NBBAMBOUY];
    cout << debug_stat(&tabbambou[49][49], 50, 50);
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
