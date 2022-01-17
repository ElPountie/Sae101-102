# sae
int tailleBambouMax(Bambou[], int taille) {
	int tailleMax = 0;
	tailleMax = Bambou[0];
	for (int i = 0; i < taille; i++) {
		if (tailleMax < Bambou[i])
		{
			tailleMax = Bambou[i];
		}
	}return tailleMax;

}
