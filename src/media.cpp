#include "media.hpp"

using namespace std;

Media::Media(){

}

Media::~Media(){

}

Media::Media(int largura, int altura){
	setLargura(largura);
	setAltura(altura);

}

void Media::armazenaPixel(ofstream &arquivodesaida){

	int largura, altura;

	largura = getLargura();
	altura = getAltura();

	int padrao, numero;
	int h = 0;
	int x = 0, y = 0;
	int Raux = 0, Gaux = 0, Baux = 0;
	int R, G, B;
	int i, j;

	cout << "\n\nEscolha o tamanho da máscara de filtro que você deseja aplicar na imagem" << endl;
	cout << "\n--------------------Dica: Digite um número ímpar--------------------" << endl;
	cout << "\nTamanho da máscara: ";

	fflush(stdin);

	while(1){

	cin >> numero;

	if(numero%2 == 0 || numero <= 0 || numero > largura || numero > altura)
	cout << "\n\nValor inválido! Digite um valor válido para o cálculo: ";

	if(numero%2 == 1 && numero > 0 && numero <= largura && numero <= altura)
	break;

	}

	padrao = (numero - 1)/2;


	for(i = 0; i < altura; i++)
	{
		for(j = 0; j < largura; j++)
		{


			for(x = i-padrao; x < i+padrao; x++){
				for(y = j-padrao; y < j+padrao; y++){

				if((x >= 0 && x < altura) && (y >= 0 && y < largura)){
				Raux = Raux + matrizR[x][y];
				Gaux = Gaux + matrizG[x][y];
				Baux = Baux + matrizB[x][y];
				h++;
				}

				}
			}

		Raux = Raux/(h*1.0);
		Gaux = Gaux/(h*1.0);
		Baux = Baux/(h*1.0);


		R = (int)Raux;
		G = (int)Gaux;
		B = (int)Baux;

		arquivodesaida << (char)R;
		arquivodesaida << (char)G;
		arquivodesaida << (char)B;

		Raux = 0;
		Gaux = 0;
		Baux = 0;
		h = 0;

		}
	}



}



