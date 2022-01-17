#include <iostream>
#include "struct.h"
#include "Const_stats_update.h"
using namespace std;

int update_bambou_size(Bambou tabbambou[][NBBAMBOUY], int taillex, int tailley) {
	for (int i1 = 0; i1 < taillex; i1++) {
		for (int i2 = 0; i2 < tailley; i2++) {
			tabbambou[i1][i2].taille += tabbambou[i1][i2].vitesse;
		}
	}
	return 0;
}