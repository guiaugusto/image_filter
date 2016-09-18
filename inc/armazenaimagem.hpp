#ifndef ARMAZENAIMAGEM_HPP
#define ARMAZENAIMAGEM_HPP
#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <sstream>


using namespace std;

class ArmazenaImagem {

private:

	string tipo;
	int largura, altura, max_cor, contadorI, contadorJ;
	int pixelR, pixelG, pixelB;

public:

	ofstream arquivosaida;
	/*typedef struct pixelrgb{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	}pxlRGB; */

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
	virtual	void armazenaPixel(int largura, int altura, int max_cor, int pixelR, int pixelG, int pixelB, int contadorI, int contadorJ, ofstream &arquivodesaida);

};
#endif
