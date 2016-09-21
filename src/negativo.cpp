#include "negativo.hpp"
#include <cstdio>
#include <cstdlib>

using namespace std;

Negativo::Negativo(){

	setLargura(0);
	setAltura(0);
	setMax_Cor(0);
}

Negativo::~Negativo(){

}

Negativo::Negativo(int largura, int altura, int max_cor){
	setLargura(largura);
	setAltura(altura);
	setMax_Cor(max_cor);
}

void Negativo::armazenaPixel(ofstream &arquivodesaida){

	int largura, altura, max_cor;

	largura = getLargura();
	altura = getAltura();
	max_cor = getMax_Cor();

	//cout << largura << " " << altura << " " << max_cor << endl;
	int i=0, j=0;


	for(i = 0; i < altura; i++)
	{
		for(j = 0; j < largura; j++)
		{
		matrizR[i][j] = max_cor - matrizR[i][j];
		arquivodesaida << matrizR[i][j];

		matrizG[i][j] = max_cor - matrizG[i][j];
		arquivodesaida << matrizG[i][j];

		matrizB[i][j] = max_cor - matrizB[i][j];
		arquivodesaida << matrizB[i][j];
		}
	}


}
