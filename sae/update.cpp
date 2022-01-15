#include <iostream>
#include "struct.h"
using namespace std;

int update_bambou_size(Bambou* tabbamboo[], int taillex, int tailley) {
	for (int i1 = 0; i1 < taillex; i1++) {
		for (int i2 = 0; i2 < tailley; i2++) {
			tabbamboo[i1][i2].taille += tabbamboo[i1][i2].vitesse;
		}
	}
	return 0;
}