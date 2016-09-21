#ifndef POLARIZADO_HPP
#define POLARIZADO_HPP

#include <iostream>
#include "armazenaimagem.hpp"

class Polarizado : public ArmazenaImagem{

public:

	Polarizado();
	~Polarizado();
	Polarizado(int largura, int altura, int max_cor);
	void armazenaPixel(ofstream &arquivodesaida);




};

#endif
