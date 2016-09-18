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
	int largura, altura, max_cor, contadorI, contadorJ;
	int pixelR, pixelG, pixelB;
	int **matrizR, **matrizG, **matrizB;
public:

	ofstream arquivosaida;
	//Métodos
	ArmazenaImagem();
	~ArmazenaImagem();
	//ArmazenaImagem(string tipo, int largura, int altura, int max_cor, pixelrgb **pxlRGB);
	ArmazenaImagem(string tipo, int largura, int altura, int max_cor, int pixelR, int pixelG, int pixelB, int contadorI, int contadorJ);
	string getTipo();
	void setTipo(string tipo);
	int getLargura();
	void setLargura(int largura);
	int getAltura();
	void setAltura(int altura);
	int getMax_Cor();
	void setMax_Cor(int max_cor);
	int getR();
	void setR(int pixelR);
	int getG();
	void setG(int pixelG);
	int getB();
	void setB(int pixelB);
	int getContadorI();
	void setContadorI(int contadorI);
	int getContadorJ();
	void setContadorJ(int contadorJ);

	void armazenaDados(ofstream &arquivodesaida);
	virtual	void armazenaPixel(ofstream &arquivodesaida);
};
#endif
