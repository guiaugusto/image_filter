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

	unsigned char **matrizR, **matrizG, **matrizB;

	ofstream arquivosaida;
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

	void armazenaDados(ofstream &arquivodesaida);
	virtual	void armazenaPixel(ofstream &arquivodesaida);

};

#endif
