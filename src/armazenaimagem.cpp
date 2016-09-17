#include "armazenaimagem.hpp"
#include <fstream>
#include <cstdio>
#include <iostream>

using namespace std;

ArmazenaImagem::ArmazenaImagem(){

	tipo = "";
	largura = 0;
	altura = 0;
	max_cor = 0;
	**pxlRGB;

}

ArmazenaImagem::~ArmazenaImagem(){

}

ArmazenaImagem::ArmazenaImagem(string tipo, int largura, int altura, int max_cor, pixelrgb **pxlRGB){
	this->tipo = tipo;
	this->largura = largura;
	this->altura = altura;
	this->max_cor = max_cor;
	this->**pxlRGB = **pxlRGB;
}

string ArmazenaImagem::getTipo(){
	return tipo;
}

void ArmazenaImagem::setTipo(string tipo){
	this->tipo = tipo;
}

int ArmazenaImagem::getLargura(){
	return largura;
}

void ArmazenaImagem::setLargura(int largura){
	this->largura = largura;
}

int ArmazenaImagem::getAltura(){
	return altura;
}

void ArmazenaImagem::setAltura(int altura){
	this->altura = altura;
}

int ArmazenaImagem::getMax_Cor(){
	return max_cor;
}

void ArmazenaImagem::setMax_Cor(int max_cor){
	this->max_cor = max_cor;
}

void ArmazenaImagem::modificaImagem(){

	ifstream arquivo1;
	string nomedoarquivo;

	//string linha = "";
	//int i = 0;

	cout << "Digite a imagem que você deseja utilizar para aplicar o filtro: ";
	//getline(cin,nomedoarquivo);
	cin >> nomedoarquivo;

	nomedoarquivo = "./doc/" + nomedoarquivo + ".ppm";

	arquivo1.open(nomedoarquivo.c_str(), ios::binary);

	if(!arquivo1.is_open())
	{

	cout << "Arquivo não encontrado!" << endl;

	}
	else
	{
	string tipo, comentario;
	int largura, altura, max_cor;

	getline(arquivo1,tipo);

	if(tipo != "P6")
	{
	cout << "Tipo de imagem inválida!" << endl;
	return;
	}

	getline(arquivo1,comentario);

	if(comentario[0] == '#')
	{
	arquivo1 >> largura;
	arquivo1 >> altura;
	arquivo1 >> max_cor;
	}
	else
	{
	largura = stoi(comentario);
	arquivo1 >> altura;
	arquivo1 >> max_cor;
	}

	unsigned r, g, b;

	ArmazenaImagem *armazena = new ArmazenaImagem(tipo, largura, altura, max_cor);

	armazena->setTipo(tipo);
	armazena->setLargura(largura);
	armazena->setAltura(altura);

	int j, k;

	for(j = 0; j < altura; j++)
	{
		for(k = 0; k < largura; k++)
		{
		arquivo1 >> r;
		arquivo1 >> g;
		arquivo1 >> b;
		//armazena->pxlRGB.R[j][k] = (int) r;
		//armazena->pxlRGB.G[j][k] = (int) g;
		//armazena->pxlRGB.B[j][k] = (int) b;
		}

	}

	}

}

void ArmazenaImagem::aplicaFiltroecriaImagem(){

	//string nomedoarquivo2;

}
