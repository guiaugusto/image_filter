#ifndef NEGATIVO_HPP
#define NEGATIVO_HPP

#include <iostream>
#include "armazenaimagem.hpp"

class Negativo : public ArmazenaImagem {

public:

	Negativo();
	~Negativo();
	Negativo(int largura, int altura, int max_cor);
	void armazenaPixel(ofstream &arquivodesaida);


};

#endif
