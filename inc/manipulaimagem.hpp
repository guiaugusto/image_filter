#ifndef MANIPULAIMAGEM_HPP
#define MANIPULAIMAGEM_HPP

#include <iostream>
#include <fstream>
#include <string>

class ManipulaImagem {

	ifstream arquivo1;
	ofstream arquivo2;

	arquivo1 = "./doc/" + arquivo1 + ".ppm";

	arquivo1.open(arquivo1);

	int i = 0;
	string palavra;
	string tipo, largura, altura, max_cor;

	if(arquivo1.is_open())
	{

	while(arquivo1.gets(palavra))
	{
	i++;

	if(i==1)
	tipo = palavra;
	if(i==2)
	largura = palavra;
	if(i==3)
	altura = palavra;
	if(i==4)
	{
	max_cor = palavra;
	break;
	}

	if(palavra[0]=='#')
	{
	getline(palavra);
	i--;
	}

	}

	std::cout << tipo << "\n" << largura << "\n" << altura << "\n" << max_cor << std::endl;

	}

	else
	std::cout << "Arquivo não encontrado! << std::endl;

	arquivo1.close();
	arquivo2.close();

};

#endif
