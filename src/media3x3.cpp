#include "media3x3.hpp"

using namespace std;

Media3x3::Media3x3(){

}

Media3x3::~Media3x3(){

}

Media3x3::Media3x3(int largura, int altura, int max_cor){
	setLargura(largura);
	setAltura(altura);
	setMax_Cor(max_cor);

}

void Media3x3::armazenaPixel(ofstream &arquivodesaida){

	int largura, altura, max_cor;

	largura = getLargura();
	altura = getAltura();
	max_cor = getMax_Cor();

	int i, j;

	char Raux, Gaux, Baux;

	for(i = 0; i < altura; i++)
	{
		for(j = 0; j < largura; j++)
		{

		if(i == 0 && j == 0)
		{
		Raux = (matrizR[i][j] + matrizR[i][j+1] + matrizR[i+1][j] + matrizR[i+1][j+1])/4;
		Gaux = (matrizG[i][j] + matrizG[i][j+1] + matrizG[i+1][j] + matrizG[i+1][j+1])/4;
		Baux = (matrizB[i][j] + matrizB[i][j+1] + matrizB[i+1][j] + matrizB[i+1][j+1])/4;
		}
		else if(i == 0 && j == largura-1)
		{
		Raux = (matrizR[i][largura-2] + matrizR[i][largura-1] + matrizR[i+1][largura-2] + matrizR[i+1][largura-1])/4;
		Gaux = (matrizG[i][largura-2] + matrizG[i][largura-1] + matrizG[i+1][largura-2] + matrizG[i+1][largura-1])/4;
		Baux = (matrizB[i][largura-2] + matrizB[i][largura-1] + matrizB[i+1][largura-2] + matrizB[i+1][largura-1])/4;
		}
		else if(i == altura-1 && j == 0)
		{
		Raux = (matrizR[altura-1][j] + matrizR[altura-2][j] + matrizR[altura-1][j+1] + matrizR[altura-2][j+1])/4;
		Gaux = (matrizG[altura-1][j] + matrizG[altura-2][j] + matrizG[altura-1][j+1] + matrizG[altura-2][j+1])/4;
		Baux = (matrizB[altura-1][j] + matrizB[altura-2][j] + matrizB[altura-1][j+1] + matrizB[altura-2][j+1])/4;
		}
		else if(i == altura-1 && j == largura-1)
		{
		Raux = (matrizR[altura-1][largura-1] + matrizR[altura-1][largura-2] + matrizR[altura-2][largura-2] + matrizR[altura-2][largura-1])/4;
		Gaux = (matrizG[altura-1][largura-1] + matrizG[altura-1][largura-2] + matrizG[altura-2][largura-2] + matrizG[altura-2][largura-1])/4;
		Baux = (matrizB[altura-1][largura-1] + matrizB[altura-1][largura-2] + matrizB[altura-2][largura-2] + matrizB[altura-2][largura-1])/4;
		}
		else if(i == 0 && j < largura-1 && j != 0)//tomar cuidado com esses casos
		{
		Raux = (matrizR[i][j-1] + matrizR[i][j+1] + matrizR[i+1][j-1] + matrizR[i+1][j] + matrizR[i][j] + matrizR[i+1][j+1])/6;
		Gaux = (matrizG[i][j-1] + matrizG[i][j+1] + matrizG[i+1][j-1] + matrizG[i+1][j] + matrizG[i][j] + matrizG[i+1][j+1])/6;
		Baux = (matrizB[i][j-1] + matrizB[i][j+1] + matrizB[i+1][j-1] + matrizB[i+1][j] + matrizB[i][j] + matrizB[i+1][j+1])/6;
		}
		else if(i < altura-1 && j == 0 && i != 0)//tomar cuidado com esses casos
		{
		Raux = (matrizR[i-1][j] + matrizR[i-1][j+1] + matrizR[i][j] + matrizR[i][j+1] + matrizR[i+1][j] + matrizR[i+1][j+1])/6;
		Gaux = (matrizG[i-1][j] + matrizG[i-1][j+1] + matrizG[i][j] + matrizG[i][j+1] + matrizG[i+1][j] + matrizG[i+1][j+1])/6;
		Baux = (matrizB[i-1][j] + matrizB[i-1][j+1] + matrizB[i][j] + matrizB[i][j+1] + matrizB[i+1][j] + matrizB[i+1][j+1])/6;
		}
		else if(i < altura-1 && j == largura-1 && j != altura-1)//tomar cuidado com esses casos
		{
		Raux = (matrizR[i-1][j-1] + matrizR[i][j-1] + matrizR[i+1][j-1] + matrizR[i][j] + matrizR[i-1][j] + matrizR[i+1][j])/6;
		Gaux = (matrizG[i-1][j-1] + matrizG[i][j-1] + matrizG[i+1][j-1] + matrizG[i][j] + matrizG[i-1][j] + matrizG[i+1][j])/6;
		Baux = (matrizB[i-1][j-1] + matrizB[i][j-1] + matrizB[i+1][j-1] + matrizB[i][j] + matrizB[i-1][j] + matrizB[i+1][j])/6;
		}
		else if(i == altura-1 && j < largura-1 && j != largura-1)//tomar cuidado com esses casos
		{
		Raux = (matrizR[i][j-1] + matrizR[i-1][j-1] + matrizR[i-1][j] + matrizR[i][j] + matrizR[i-1][j+1] + matrizR[i][j+1])/6;
		Gaux = (matrizG[i][j-1] + matrizG[i-1][j-1] + matrizG[i-1][j] + matrizG[i][j] + matrizG[i-1][j+1] + matrizG[i][j+1])/6;
		Baux = (matrizB[i][j-1] + matrizB[i-1][j-1] + matrizB[i-1][j] + matrizB[i][j] + matrizB[i-1][j+1] + matrizB[i][j+1])/6;
		}
		else
		{
		Raux = (matrizR[i][j] + matrizR[i-1][j-1] + matrizR[i-1][j] + matrizR[i-1][j+1] + matrizR[i][j-1] + matrizR[i][j+1] + matrizR[i+1][j-1] + matrizR[i+1][j] + matrizR[i+1][j+1])/9;
		Gaux = (matrizG[i][j] + matrizG[i-1][j-1] + matrizG[i-1][j] + matrizG[i-1][j+1] + matrizG[i][j-1] + matrizG[i][j+1] + matrizG[i+1][j-1] + matrizG[i+1][j] + matrizG[i+1][j+1])/9;
		Baux = (matrizB[i][j] + matrizB[i-1][j-1] + matrizB[i-1][j] + matrizB[i-1][j+1] + matrizB[i][j-1] + matrizB[i][j+1] + matrizB[i+1][j-1] + matrizB[i+1][j] + matrizB[i+1][j+1])/9;
		}
		arquivodesaida << Raux;
		arquivodesaida << Gaux;
		arquivodesaida << Baux;


		}
	}


}

