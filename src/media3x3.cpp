#include "media3x3.hpp"

using namespace std;

Media3x3::Media3x3(){

}

Media3x3::~Media3x3(){

}

Media3x3::Media3x3(int largura, int altura){
	setLargura(largura);
	setAltura(altura);
	//setMax_Cor(max_cor);

}

void Media3x3::armazenaPixel(ofstream &arquivodesaida){

	int largura, altura;

	largura = getLargura();
	altura = getAltura();
	//max_cor = getMax_Cor();



	//int Raux = 0, Gaux = 0, Baux = 0;
	int numero, padrao;
	int h = 0;
	int R, G, B;
	int x = 0, y = 0;
	//unsigned char **Rvai, **Gvai, **Bvai;
	int Raux = 0, Gaux = 0, Baux = 0;
/*
	Rvai = new unsigned char*[largura];
	for(int i = 0; i < largura-1; i++)
	Rvai[i] = new unsigned char[altura];

        Gvai = new unsigned char*[largura];
        for(int i = 0; i < largura-1; i++)
	Gvai[i] = new unsigned char[altura];

        Bvai = new unsigned char*[largura];
        for(int i = 0; i < largura-1; i++)
	Bvai[i] = new unsigned char[altura];
*/
/*	for(int i = 0; i < altura-1; i++)
	{
		for(int j = 0; j < largura-1; j++)
		{
		Rvai[i][j] = 0;
		Gvai[i][j] = 0;
		Bvai[i][j] = 0;
		}
	}
*/
	int i, j;

	cout << "Digite o tamanho da máscara de filtro que você deseja aplicar na imagem: " << endl;
	cin >> numero;

	padrao = (numero - 1)/2;

	for(i = 0; i < altura; i++)
	{
		for(j = 0; j < largura; j++)
		{


		x = i;
		y = j;

		if(y - padrao < 0 ){
		while(y - padrao < 0)
                {
                y++;
                };
		}
		else if(y + padrao > largura-1){
		while(y + padrao > largura-1)
		y--;
		}

		if(x - padrao < 0){
		while(x - padrao < 0){
                x++;
                };
		}
		else if(x + padrao > altura-1){
		while(x + padrao > altura-1){
		x--;
		};
		}

		//while(altura-1 - padrao < 0 || altura-1 

/*
		while(var1 - padrao < 0 || var1 + padrao > altura-1)
                {
                if(var1 < 0)
                var1++;
                }
*/

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
		//Rvai[i][j] = Raux/(h*1.0);
		//Gvai[i][j] = Gaux/(h*1.0);
		//Bvai[i][j] = Baux/(h*1.0);

		Raux = Raux/(h*1.0);
		Gaux = Gaux/(h*1.0);
		Baux = Baux/(h*1.0);

		//Raux = (matrizR[i][j] + matrizR[i][j+1] + matrizR[i+1][j] + matrizR[i+1][j+1])/4;
		//Gaux = (matrizG[i][j] + matrizG[i][j+1] + matrizG[i+1][j] + matrizG[i+1][j+1])/4;
		//Baux = (matrizB[i][j] + matrizB[i][j+1] + matrizB[i+1][j] + matrizB[i+1][j+1])/4;
		}
		else if(i == 0 && j == largura-1)
		{

/*		while(y - padrao < 0 || y + padrao > altura-1){
                if(y - padrao < 0)
                y++;
                if(y + padrao > altura-1)
                y--;
                };
*/


		for(int k = 0; k <= padrao; k++)
		{
			for(int l = largura-1; l >= largura-1-padrao; l--)
			{

                        //Rvai[i][j] = Rvai[i][j] + matrizR[k][l];
                        //Gvai[i][j] = Gvai[i][j] + matrizG[k][l];
                        //Bvai[i][j] = Bvai[i][j] + matrizB[k][l];


			Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];

			h++;
			}
		}

                //Rvai[i][j] = Raux/(h*1.0);
                //Gvai[i][j] = Gaux/(h*1.0);
                //Bvai[i][j] = Baux/(h*1.0);

		Raux = Raux/(h*1.0);
		Gaux = Gaux/(h*1.0);
		Baux = Baux/(h*1.0);


		//Raux = (matrizR[i][largura-2] + matrizR[i][largura-1] + matrizR[i+1][largura-2] + matrizR[i+1][largura-1])/4;
		//Gaux = (matrizG[i][largura-2] + matrizG[i][largura-1] + matrizG[i+1][largura-2] + matrizG[i+1][largura-1])/4;
		//Baux = (matrizB[i][largura-2] + matrizB[i][largura-1] + matrizB[i+1][largura-2] + matrizB[i+1][largura-1])/4;
		}
		else if(i == altura-1 && j == 0)
		{
/*		while(altura - 1 - padrao < 0)
		{
		if(altura-1 < 0)
		altura++;
		}
*/
/*		while(x - padrao < 0 || x + padrao > altura-1){
                if(x - padrao < 0)
                x++;
                if(x + padrao > altura-1)
                x--;
                };
*/

		for(int k = altura-1; k >= altura-1-padrao; k--)
		{


			for(int l = 0; l <= padrao; l++)
		 	{

                        //Rvai[i][j] = Rvai[i][j] + matrizR[k][l];
                        //Gvai[i][j] = Gvai[i][j] + matrizG[k][l];
                        //Bvai[i][j] = Bvai[i][j] + matrizB[k][l];


                        Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];
                        h++;
                        }
                }


                //Rvai[i][j] = Raux/(h*1.0);
                //Gvai[i][j] = Gaux/(h*1.0);
                //Bvai[i][j] = Baux/(h*1.0);

                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);

		//Raux = (matrizR[altura-1][j] + matrizR[altura-2][j] + matrizR[altura-1][j+1] + matrizR[altura-2][j+1])/4;
		//Gaux = (matrizG[altura-1][j] + matrizG[altura-2][j] + matrizG[altura-1][j+1] + matrizG[altura-2][j+1])/4;
		//Baux = (matrizB[altura-1][j] + matrizB[altura-2][j] + matrizB[altura-1][j+1] + matrizB[altura-2][j+1])/4;
		}
		else if(i == altura-1 && j == largura-1)
		{
/*
		while(largura - 1 - padrao < 0){
		largura++;
                };

		while(altura - 1 - padrao < 0){
		altura++;
		};
*/
		for(int k = altura-1; k < altura-1-padrao; k--)
		{
			for(int l = largura-1; l < largura-1-padrao; l--)
			{

                        //Rvai[i][j] = Rvai[i][j] + matrizR[k][l];
                        //Gvai[i][j] = Gvai[i][j] + matrizG[k][l];
                        //Bvai[i][j] = Bvai[i][j] + matrizB[k][l];


                        Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];
                        h++;
                        }
                }

                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);

                //Rvai[i][j] = Raux/(h*1.0);
                //Gvai[i][j] = Gaux/(h*1.0);
                //Bvai[i][j] = Baux/(h*1.0);

		//Raux = (matrizR[altura-1][largura-1] + matrizR[altura-1][largura-2] + matrizR[altura-2][largura-2] + matrizR[altura-2][largura-1])/4;
		//Gaux = (matrizG[altura-1][largura-1] + matrizG[altura-1][largura-2] + matrizG[altura-2][largura-2] + matrizG[altura-2][largura-1])/4;
		//Baux = (matrizB[altura-1][largura-1] + matrizB[altura-1][largura-2] + matrizB[altura-2][largura-2] + matrizB[altura-2][largura-1])/4;
		}
		else if(i == 0 && j < largura-1 && j != 0)//tomar cuidado com esses casos
		{
                for(int k = 0; k <= padrao; k++)
                {
/*			while(y - padrao < 0 || y + padrao > largura-1)
			{
			if(y - padrao < 0)
			y++;
			if(y + padrao > largura-1)
			y--;
			};
*/
                        for(int l = y-padrao; l <= y+padrao; l++)
                        {

                        //Rvai[i][j] = Rvai[i][j] + matrizR[k][l];
                        //Gvai[i][j] = Gvai[i][j] + matrizG[k][l];
                        //Bvai[i][j] = Bvai[i][j] + matrizB[k][l];


                        Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];
                        h++;
                        }
                }
                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);

                //Rvai[i][j] = Raux/(h*1.0);
                //Gvai[i][j] = Gaux/(h*1.0);
                //Bvai[i][j] = Baux/(h*1.0);

		//Raux = (matrizR[i][j-1] + matrizR[i][j+1] + matrizR[i+1][j-1] + matrizR[i+1][j] + matrizR[i][j] + matrizR[i+1][j+1])/6;
		//Gaux = (matrizG[i][j-1] + matrizG[i][j+1] + matrizG[i+1][j-1] + matrizG[i+1][j] + matrizG[i][j] + matrizG[i+1][j+1])/6;
		//Baux = (matrizB[i][j-1] + matrizB[i][j+1] + matrizB[i+1][j-1] + matrizB[i+1][j] + matrizB[i][j] + matrizB[i+1][j+1])/6;
		}
		else if(i < altura-1 && j == 0 && i > 0)//tomar cuidado com esses casos
		{

/*
		while(x - padrao < 0 || x + padrao > altura-1){
		if(x - padrao < 0)
		x++;
		if(x + padrao > altura-1)
		x--;
		};
*/
		for(int k = x-padrao; k <= x+padrao; k++)
                {

                        for(int l = 0; l <= padrao; l++)
                        {

                        //Rvai[i][j] = Rvai[i][j] + matrizR[k][l];
                        //Gvai[i][j] = Gvai[i][j] + matrizG[k][l];
                        //Bvai[i][j] = Bvai[i][j] + matrizB[k][l];


                        Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[i][j];
                        h++;
                        }
                }
                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);

                //Rvai[i][j] = Raux/(h*1.0);
                //Gvai[i][j] = Gaux/(h*1.0);
                //Bvai[i][j] = Baux/(h*1.0);

		//Raux = (matrizR[i-1][j] + matrizR[i-1][j+1] + matrizR[i][j] + matrizR[i][j+1] + matrizR[i+1][j] + matrizR[i+1][j+1])/6;
		//Gaux = (matrizG[i-1][j] + matrizG[i-1][j+1] + matrizG[i][j] + matrizG[i][j+1] + matrizG[i+1][j] + matrizG[i+1][j+1])/6;
		//Baux = (matrizB[i-1][j] + matrizB[i-1][j+1] + matrizB[i][j] + matrizB[i][j+1] + matrizB[i+1][j] + matrizB[i+1][j+1])/6;
		}
		else if(i < altura-1 && j == largura-1 && i > 0)//tomar cuidado com esses casos
		{
/*
		while(x - padrao < 0 || x + padrao > altura-1)
		{
		if(x - padrao < 0)
		x++;
		if(x + padrao > altura-1)
		x--;
		};


		while(y - padrao < 0 || y + padrao > largura-1){
                if(y - padrao < 0)
                y++;
                if(y + padrao > largura-1)
                y--;
                };

*/
		for(int k = x-padrao; k >= x+padrao; k++)
                {

                        for(int l = largura-1-padrao; l <= largura-1; l++)
                        {

                        //Rvai[i][j] = Rvai[i][j] + matrizR[k][l];
                        //Gvai[i][j] = Gvai[i][j] + matrizG[k][l];
                        //Bvai[i][j] = Bvai[i][j] + matrizB[k][l];


                        Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];
                        h++;
                        }
                }
                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);

                //Rvai[i][j] = Raux/(h*1.0);
                //Gvai[i][j] = Gaux/(h*1.0);
                //Bvai[i][j] = Baux/(h*1.0);

		//Raux = (matrizR[i-1][j-1] + matrizR[i][j-1] + matrizR[i+1][j-1] + matrizR[i][j] + matrizR[i-1][j] + matrizR[i+1][j])/6;
		//Gaux = (matrizG[i-1][j-1] + matrizG[i][j-1] + matrizG[i+1][j-1] + matrizG[i][j] + matrizG[i-1][j] + matrizG[i+1][j])/6;
		//Baux = (matrizB[i-1][j-1] + matrizB[i][j-1] + matrizB[i+1][j-1] + matrizB[i][j] + matrizB[i-1][j] + matrizB[i+1][j])/6;
		}
		else if(i == altura-1 && j < largura-1)//tomar cuidado com esses casos
		{
		for(int k = altura-1-padrao; k <= altura-1; k++)
                {

/*
			while(y - padrao < 0 || y + padrao > largura-1)
			{
			if(y - padrao < 0)
			y++;
			if(y + padrao > largura-1)
			y--;
			};
*/
                        for(int l = y-padrao; l <= y+padrao; l++)
                        {

                        //Rvai[i][j] = Rvai[i][j] + matrizR[k][l];
                        //Gvai[i][j] = Gvai[i][j] + matrizG[k][l];
                        //Bvai[i][j] = Bvai[i][j] + matrizB[k][l];


                        Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];
                        h++;
                        }
                }
                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);

                //Rvai[i][j] = Raux/(h*1.0);
                //Gvai[i][j] = Gaux/(h*1.0);
                //Bvai[i][j] = Baux/(h*1.0);

		//Raux = (matrizR[i][j-1] + matrizR[i-1][j-1] + matrizR[i-1][j] + matrizR[i][j] + matrizR[i-1][j+1] + matrizR[i][j+1])/6;
		//Gaux = (matrizG[i][j-1] + matrizG[i-1][j-1] + matrizG[i-1][j] + matrizG[i][j] + matrizG[i-1][j+1] + matrizG[i][j+1])/6;
		//Baux = (matrizB[i][j-1] + matrizB[i-1][j-1] + matrizB[i-1][j] + matrizB[i][j] + matrizB[i-1][j+1] + matrizB[i][j+1])/6;
		}
		else
		{
/*
		while(x - padrao < 0 || x + padrao > altura-1)
		{
		if(x - padrao < 0)
		x++;
		if(x + padrao > altura-1)
		x--;
		};
*/
		  for(int k = x-padrao; k <= x+padrao; k++)
                {
/*			while(y - padrao < 0 || y + padrao > largura-1)
			{
			if(y - padrao < 0)
			y++;
			if(y + padrao > altura-1)
			y--;
			};
*/
                        for(int l = y-padrao; l <= y+padrao; l++)
                        {


                        //Rvai[i][j] = Rvai[i][j] + matrizR[k][l];
                        //Gvai[i][j] = Gvai[i][j] + matrizG[k][l];
                        //Bvai[i][j] = Bvai[i][j] + matrizB[k][l];


                        Raux = Raux + matrizR[k][l];
                        Gaux = Gaux + matrizG[k][l];
                        Baux = Baux + matrizB[k][l];
                        h++;
                        }
                }
                Raux = Raux/(h*1.0);
                Gaux = Gaux/(h*1.0);
                Baux = Baux/(h*1.0);

                //Rvai[i][j] = Raux/(h*1.0);
                //Gvai[i][j] = Gaux/(h*1.0);
                //Bvai[i][j] = Baux/(h*1.0);

		//cout << "Passou pela ultima opção" << endl;
		//Raux = (matrizR[i][j] + matrizR[i-1][j-1] + matrizR[i-1][j] + matrizR[i-1][j+1] + matrizR[i][j-1] + matrizR[i][j+1] + matrizR[i+1][j-1] + matrizR[i+1][j] + matrizR[i+1][j+1])/9;
		//Gaux = (matrizG[i][j] + matrizG[i-1][j-1] + matrizG[i-1][j] + matrizG[i-1][j+1] + matrizG[i][j-1] + matrizG[i][j+1] + matrizG[i+1][j-1] + matrizG[i+1][j] + matrizG[i+1][j+1])/9;
		//Baux = (matrizB[i][j] + matrizB[i-1][j-1] + matrizB[i-1][j] + matrizB[i-1][j+1] + matrizB[i][j-1] + matrizB[i][j+1] + matrizB[i+1][j-1] + matrizB[i+1][j] + matrizB[i+1][j+1])/9;
		}

		R = (int)Raux;
		G = (int)Gaux;
		B = (int)Baux;

		if(R  > 255)
		R = 255;
		if(G > 255)
		G = 255;
		if(B > 255)
		B = 255;

//		Rvai[i][j] = (unsigned char)R;
//		Gvai[i][j] = (unsigned char)G;
//		Bvai[i][j] = (unsigned char)B;


		arquivodesaida << (char)R;
		arquivodesaida << (char)G;
		arquivodesaida << (char)B;

		Raux = 0;
		Gaux = 0;
		Baux = 0;
		h = 0;

		}
	}

	//cout << Rvai[156][0] << endl;


}
/*	for(i = 0; i < altura-1; i++)
	{
		for(j = 0; j < largura-1; j++)
		{
		arquivodesaida << Rvai[i][j];
                arquivodesaida << Gvai[i][j];
                arquivodesaida << Bvai[i][j];

		}
	}*/

/*
	for(int i = 0; i < altura; i++)
	{
		for(int j = 0; j < largura; j++)
		{
		arquivodesaida << Rvai[i][j];
		arquivodesaida << Gvai[i][j];
		arquivodesaida << Bvai[i][j];
		}
	}
*/



