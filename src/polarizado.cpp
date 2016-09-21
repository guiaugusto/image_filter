#include "polarizado.hpp"

using namespace std;

Polarizado::Polarizado(){

	setLargura(0);
	setAltura(0);
	setMax_Cor(0);

}

Polarizado::~Polarizado(){

}

Polarizado::Polarizado(int largura, int altura, int max_cor){
	setLargura(largura);
	setAltura(altura);
	setMax_Cor(max_cor);

}

void Polarizado::armazenaPixel(ofstream &arquivodesaida){

	int largura, altura, max_cor;

	largura = getLargura();
	altura = getAltura();
	max_cor = getMax_Cor();

	unsigned int Raux, Gaux, Baux;

	int i, j;

	for(i = 0; i < altura; i++)
	{
		for(j = 0; j < largura; j++)
		{
		Raux = matrizR[i][j];
		if(Raux > (unsigned int)max_cor/2)
		matrizR[i][j] = max_cor;
		else
		matrizR[i][j] = 0;

		Gaux = matrizG[i][j];
		if(Gaux > (unsigned int)max_cor/2)
		matrizG[i][j] = max_cor;
		else
		matrizG[i][j] = 0;

		Baux = matrizB[i][j];
		if(Baux > (unsigned int)max_cor/2)
		matrizB[i][j] = max_cor;
		else
		matrizB[i][j] = 0;

		arquivodesaida << matrizR[i][j];
		arquivodesaida << matrizG[i][j];
		arquivodesaida << matrizB[i][j];


		}

	}


}
