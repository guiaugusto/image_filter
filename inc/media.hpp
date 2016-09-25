#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <iostream>
#include "armazenaimagem.hpp"

class Media : public ArmazenaImagem{

public:

 	Media();
	~Media();
	Media(int largura, int altura);
	void armazenaPixel(ofstream &arquivodesaida);



};
#endif
