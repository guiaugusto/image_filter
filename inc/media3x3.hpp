#ifndef MEDIA3X3_HPP
#define MEDIA3X3_HPP

#include <iostream>
#include "armazenaimagem.hpp"

class Media3x3 : public ArmazenaImagem{

public:

	Media3x3();
	~Media3x3();
	Media3x3(int largura, int altura, int max_cor);
	void armazenaPixel(ofstream &arquivodesaida);



};
#endif
