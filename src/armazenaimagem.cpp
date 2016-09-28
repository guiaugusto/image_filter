#include "armazenaimagem.hpp"
#include <fstream>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

ArmazenaImagem::ArmazenaImagem(){

	tipo = "";
	largura = 0;
	altura = 0;
	max_cor = 255;

	matrizR = new unsigned char*[altura];
	for(int i = 0; i < altura; i++)
	matrizR[i] = new unsigned char[largura];

	matrizG = new unsigned char*[altura];
	for(int i = 0; i < altura; i++)
	matrizG[i] = new unsigned char[largura];

	matrizB = new unsigned char*[altura];
	for(int i = 0; i < altura; i++)
	matrizB[i] = new unsigned char[largura];

}

ArmazenaImagem::~ArmazenaImagem(){

}

ArmazenaImagem::ArmazenaImagem(string tipo, int largura, int altura, int max_cor){
	this->tipo = tipo;
	this->largura = largura;
	this->altura = altura;
	this->max_cor = max_cor;
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

void ArmazenaImagem::armazenaDados(ofstream &arquivodesaida){

	ifstream arquivodeentrada;
	string nomedoarquivodeentrada;

	system("clear");

	cout << "\nDigite a imagem que você deseja utilizar sem a extensão para aplicar o filtro: ";
	getline(cin,nomedoarquivodeentrada);

	nomedoarquivodeentrada = "./doc/" + nomedoarquivodeentrada + ".ppm";

	arquivodeentrada.open(nomedoarquivodeentrada.c_str(), ios::binary);

	if(!arquivodeentrada.is_open())
	{

	cout << "\n\nArquivo não encontrado ou tipo de imagem inválida.\n" << endl;
	return;
	}
	else
	{
	string tipo, comentario, comentarioaux;
	int largura, altura, max_cor;

	getline(arquivodeentrada,tipo);

	if(tipo != "P6")
	{
	cout << "\n\nTipo de imagem inválida!\n" << endl;
	return;
	}

	while(1)
	{

	getline(arquivodeentrada,comentario);

	if(comentario[0] != '#')
	{
	int tamanho = comentario.length()+1;
	arquivodeentrada.seekg(-tamanho,ios_base::cur);
	arquivodeentrada >> largura;
	arquivodeentrada >> altura;
	arquivodeentrada >> max_cor;
	break;
	}

	}


	setTipo(tipo);
	setLargura(largura);
	setAltura(altura);
	setMax_Cor(max_cor);

	arquivodeentrada.seekg(1,ios_base::cur);

	string nomedoarquivodesaida;

	cout << "\n\nDigite o nome da nova imagem criada pelo filtro selecionado: ";
	getline(cin,nomedoarquivodesaida);

	nomedoarquivodesaida = "./doc/" + nomedoarquivodesaida + ".ppm";

	while(nomedoarquivodesaida == nomedoarquivodeentrada)
	{
	cout << "\n\nNome de arquivo inválido. Por favor, insira um novo nome: ";
	getline(cin,nomedoarquivodesaida);
	}

	arquivodesaida.open(nomedoarquivodesaida.c_str(),ios::binary);

	if(!arquivodesaida.is_open()){
	system("clear");
	cout << "\n\n\n\n\n\tErro na criação do novo arquivo!\n" << endl;
	return;
	}

	arquivodesaida << tipo << endl;
	arquivodesaida << largura << " " << altura << endl;
	arquivodesaida << max_cor << endl;

	int j, k;
	char r, g, b;

	matrizR = new unsigned char*[altura];
	for(int i = 0; i < altura; i++)
	matrizR[i] = new unsigned char[largura];

	matrizG = new unsigned char*[altura];
	for(int i = 0; i < altura; i++)
	matrizG[i] = new unsigned char[largura];

	matrizB = new unsigned char*[altura];
	for(int i = 0; i < altura; i++)
	matrizB[i] = new unsigned char[largura];


	for(j = 0; j < altura; j++)
	{
		for(k = 0; k < largura; k++)
		{
		arquivodeentrada.get(r);
		arquivodeentrada.get(g);
		arquivodeentrada.get(b);
		matrizR[j][k] = r;
		matrizG[j][k] = g;
		matrizB[j][k] = b;
		}

	}

	}

	armazenaPixel(arquivodesaida);

	cout << "\n\nImagem nova criada com sucesso!\n\n" << endl;

	arquivodeentrada.close();
	arquivodesaida.close();

}

void ArmazenaImagem::armazenaPixel(ofstream &arquivodesaida){


	int **Raux, **Gaux, **Baux;

	Raux = new int*[altura];
	for(int i = 0; i < altura; i++)
	Raux[i] = new int[largura];

	Gaux = new int*[altura];
	for(int i = 0; i < altura; i++)
	Gaux[i] = new int[largura];

	Baux = new int*[altura];
	for(int i = 0; i < altura; i++)
	Baux[i] = new int[largura];


	int i, j;

	for(i = 0; i < altura; i++)
	{
		for(j = 0; j < largura; j++)
		{
		Raux[i][j] = (unsigned int)matrizR[i][j];
		arquivodesaida << (char)Raux[i][j];
		Gaux[i][j] = (unsigned int)matrizG[i][j];
		arquivodesaida << (char)Gaux[i][j];
		Baux[i][j] = (unsigned int)matrizB[i][j];
		arquivodesaida << (char)Baux[i][j];
		}
	}


}

