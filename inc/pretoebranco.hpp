#ifndef PRETOEBRANCO_HPP
#define PRETOEBRANCO_HPP

#include <iostream>
#include "armazenaimagem.hpp"

class PretoeBranco : public ArmazenaImagem {

public:

	PretoeBranco();
	~PretoeBranco();
	PretoeBranco(int largura, int altura, int max_cor);
	void armazenaPixel(ofstream &arquivodesaida);



};

#endif
