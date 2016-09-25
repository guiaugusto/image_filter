#include "media.hpp"
#include <cstdio>
#include <cstdlib>

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

	if(numero%2 == 0 || numero <= 0)
	cout << "\n\nValor inválido! Digite um valor válido para o cálculo: ";

	if(numero%2 == 1 && numero > 0)
	break;

	}


	padrao = (numero - 1)/2;

	for(i = 0; i < altura; i++)
	{
		for(j = 0; j < largura; j++)
		{


		x = i;
		y = j;

		if(i == 0 && j == 0)
		{

		for(int k = 0; k <= padrao; k++)
		{
			for(int l = 0; l <= padrao; l++)
			{
			Raux = Raux + matrizR[k][l];
			Gaux = Gaux + matrizG[k][l];
			Baux = Baux + matrizB[k][l];
			h++;
			}
		}

		Raux = Raux/(h*1.0);
		Gaux = Gaux/(h*1.0);
		Baux = Baux/(h*1.0);

		}
		else if(i == 0 && j == largura-1)
		{


		for(int k = 0; k <= padrao; k++)
		{
			for(int l = largura-1; l >= largura-1-padrao; l--)
			{

			Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];

			h++;
			}
		}

		Raux = Raux/(h*1.0);
		Gaux = Gaux/(h*1.0);
		Baux = Baux/(h*1.0);

		}
		else if(i == altura-1 && j == 0)
		{

		for(int k = altura-1; k >= altura-1-padrao; k--)
		{


			for(int l = 0; l <= padrao; l++)
		 	{

                        Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];
                        h++;
                        }
                }

                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);

		}
		else if(i == altura-1 && j == largura-1)
		{

		for(int k = altura-1; k >= altura-1-padrao; k--)
		{
			for(int l = largura-1; l >= largura-1-padrao; l--)
			{

                        Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];
                        h++;
                        }
                }

                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);

		}
		else if(i == 0 && j < largura-1 && j > 0)
		{

                for(int k = 0; k <= padrao; k++)
                {
			while(y - padrao < 0 || y + padrao > largura-1)
			{
			if(y - padrao < 0)
			y++;
			if(y + padrao > largura-1)
			y--;
			};

                        for(int l = y-padrao; l <= y+padrao; l++)
                        {

                        Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];
                        h++;
                        }
                }

                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);

		}
		else if(i < altura-1 && j == 0 && i > 0)
		{


		while(x - padrao < 0 || x + padrao > altura-1){
		if(x - padrao < 0)
		x++;
		if(x + padrao > altura-1)
		x--;
		};

		for(int k = x-padrao; k <= x+padrao; k++)
                {

                        for(int l = 0; l <= padrao; l++)
                        {

                        Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[i][j];
                        h++;
                        }
                }
                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);
		}
		else if(i < altura-1 && j == largura-1 && i > 0)
		{

		while(x - padrao < 0 || x + padrao > altura-1)
		{
		if(x - padrao < 0)
		x++;
		if(x + padrao > altura-1)
		x--;
		};

		for(int k = x-padrao; k <= x+padrao; k++)
                {

                        for(int l = largura-1; l >= largura-1-padrao; l--)
                        {

                        Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];
                        h++;
                        }
                }
                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);


		}
		else if(i == altura-1 && j < largura-1 && j > 0)
		{
		for(int k = altura-1; k >= altura-1-padrao; k--)
                {


			while(y - padrao < 0 || y + padrao > largura-1)
			{
			if(y - padrao < 0)
			y++;
			if(y + padrao > largura-1)
			y--;
			};

                        for(int l = y-padrao; l <= y+padrao; l++)
                        {

			Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];
                        h++;
                        }
                }
                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);

		}
		else
		{

		while(x - padrao < 0 || x + padrao > altura-1)
		{
		if(x - padrao < 0)
		x++;
		if(x + padrao > altura-1)
		x--;
		};

		  for(int k = x-padrao; k <= x+padrao; k++)
                {
			while(y - padrao < 0 || y + padrao > largura-1)
			{
			if(y - padrao < 0)
			y++;
			if(y + padrao > altura-1)
			y--;
			};

                        for(int l = y-padrao; l <= y+padrao; l++)
                        {


                        Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];
                        h++;
                        }
                }
                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);

		}

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



