#include "negativo.hpp"

using namespace std;

Negativo::Negativo(){

	setLargura(0);
	setAltura(0);
	setMax_Cor(0);
	//setMatrizR(0);
	//setMatrizG(0);
	//setMatrizB(0);
}

Negativo::~Negativo(){

}

Negativo::Negativo(int largura, int altura, int max_cor){
	setLargura(largura);
	setAltura(altura);
	setMax_Cor(max_cor);
	//setMatrizR(matrizR);
	//setMatrizG(matrizG);
	//setMatrizB(matrizB);
	//this->largura = largura;
	//this->altura = altura;
	//this->max_cor = max_cor;
	//this->matrizR = matrizR;
	//this->matrizG = matrizG;
	//this->matrizB = matrizB;

}

void Negativo::armazenaPixel(ofstream &arquivodesaida){

	int largura, altura, max_cor;
	//int **matrizR, **matrizG, **matrizB;

	largura = getLargura();
	altura = getAltura();
	max_cor = getMax_Cor();

/*
	matrizR = new int*[altura];
	for(int x = 0; x < altura; x++)
	matrizR[x] = new int[largura];

	matrizG = new int*[altura];
	for(int x = 0; x < altura; x++)
	matrizG[x] = new int[largura];


	matrizB = new int*[altura];
	for(int x = 0; x < altura; x++)
	matrizB[x] = new int[largura];
*/

	int Raux[altura][largura], Gaux[altura][largura], Baux[altura][largura];

	//cout << matrizR[0][0] << endl;



	for(int i = 0; i < altura; i++)
	{
		for(int j = 0; i < largura; j++)
		{
		//matrizR[i][j] = **getMatrizR();
		Raux[i][j] = max_cor - matrizR[i][j];
		arquivodesaida.put((char)Raux[i][j]);
		//matrizG[i][j] = **getMatrizG();
		Gaux[i][j] = max_cor - matrizG[i][j];
		arquivodesaida.put((char)Gaux[i][j]);
		//matrizB[i][j] = **getMatrizB();
		Baux[i][j] = max_cor - matrizB[i][j];
		arquivodesaida.put((char)Baux[i][j]);
		}

	}

	//cout << matrizR[161][299] << " " << matrizG[161][299] << " " << matrizB[161][299] << endl;
	//free(matrizR);
	//free(matrizG);
	//free(matrizB);

	//arquivodesaida.close();

}
