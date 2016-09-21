#include "pretoebranco.hpp"

using namespace std;

PretoeBranco::PretoeBranco(){

	setLargura(0);
	setAltura(0);
	setMax_Cor(0);

}

PretoeBranco::~PretoeBranco(){

}

PretoeBranco::PretoeBranco(int largura, int altura, int max_cor){
	setLargura(largura);
	setAltura(altura);
	setMax_Cor(max_cor);

}

void PretoeBranco::armazenaPixel(ofstream &arquivodesaida){

	int largura, altura, max_cor;

	largura = getLargura();
	altura = getAltura();
	max_cor = getMax_Cor();

	int i, j;

	char cinza;

	for(i = 0; i < altura; i++)
	{
		for(j = 0; j < largura; j++)
		{
		cinza = (0.299*matrizR[i][j]) + (0.587*matrizG[i][j]) + (0.144*matrizB[i][j]);
		if(cinza > max_cor)
		{
		matrizR[i][j] = max_cor;
		matrizG[i][j] = max_cor;
		matrizB[i][j] = max_cor;
		arquivodesaida << matrizR[i][j];
		arquivodesaida << matrizG[i][j];
		arquivodesaida << matrizB[i][j];
		}
		else
		{
		matrizR[i][j] = cinza;
		matrizG[i][j] = cinza;
		matrizB[i][j] = cinza;
		arquivodesaida << matrizR[i][j];
		arquivodesaida << matrizG[i][j];
		arquivodesaida << matrizB[i][j];
		}

		}

	}



}
