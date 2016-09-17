#ifndef ARMAZENAIMAGEM_HPP
#define ARMAZENAIMAGEM_HPP

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class ArmazenaImagem {

public:

	typedef struct pixelrgb{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	}pixelrgb;

private:

	string tipo;
	int largura, altura, max_cor;
	pixelrgb **pxlRGB;

public:

	//Métodos
	ArmazenaImagem();
	~ArmazenaImagem();
	ArmazenaImagem(string tipo, int largura, int altura, int max_cor, pixelrgb **pxlRGB);
	//ArmazenaImagem(string tipo, int largura, int altura, int max_cor);
	string getTipo();
	void setTipo(string tipo);
	int getLargura();
	void setLargura(int largura);
	int getAltura();
	void setAltura(int altura);
	int getMax_Cor();
	void setMax_Cor(int max_cor);
	//pixelrgb getRGB();
	//void setRGB(pixelrgb pxlRGB[][]);


	void modificaImagem();
	virtual	void aplicaFiltroecriaImagem();

};
#endif
