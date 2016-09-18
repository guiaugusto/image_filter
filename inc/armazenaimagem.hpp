#ifndef ARMAZENAIMAGEM_HPP
#define ARMAZENAIMAGEM_HPP
#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstdlib>

using namespace std;

class ArmazenaImagem {

private:

	string tipo;
	int largura, altura, max_cor;

public:

	int **matrizR, **matrizG, **matrizB;
	//int matrizR[altura][largura], matrizG[altura][largura], matrizB[altura][largura];
/*
	int i;

	matrizR = new int*[altura];
	for(i = 0; i < altura; i++)
	matrizR[i] = new int[largura];

	matrizG = new int*[altura];
	for(i = 0; i < altura; i++)
	matrizG[i] = new int[largura];

	matrizB = new int*[altura];
	for(i = 0; i < altura; i++)
	matrizB[i] = new int[largura];
*/
	ofstream arquivosaida;
	//Métodos
	ArmazenaImagem();
	~ArmazenaImagem();
	ArmazenaImagem(string tipo, int largura, int altura, int max_cor);
	string getTipo();
	void setTipo(string tipo);
	int getLargura();
	void setLargura(int largura);
	int getAltura();
	void setAltura(int altura);
	int getMax_Cor();
	void setMax_Cor(int max_cor);
/*	int ** getMatrizR();
	void setMatrizR(int **matrizR);
	int ** getMatrizG();
	void setMatrizG(int **matrizG);
	int ** getMatrizB();
	void setMatrizB(int **matrizB); */

	void armazenaDados(ofstream &arquivodesaida);
	virtual	void armazenaPixel(ofstream &arquivodesaida);
};
#endif
