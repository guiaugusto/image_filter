#include "armazenaimagem.hpp"
#include <fstream>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

ArmazenaImagem::ArmazenaImagem(){

	tipo = "";
	largura = 0;
	altura = 0;
	max_cor = 255;
	contadorI = 0;
	contadorJ = 0;
	pixelR = 0;
	pixelG = 0;
	pixelB = 0;
}

ArmazenaImagem::~ArmazenaImagem(){

}

ArmazenaImagem::ArmazenaImagem(string tipo, int largura, int altura, int max_cor, int pixelR, int pixelG, int pixelB, int contadorI, int contadorJ){
	this->tipo = tipo;
	this->largura = largura;
	this->altura = altura;
	this->max_cor = max_cor;
	this->pixelR = pixelR;
	this->pixelG = pixelG;
	this->pixelB = pixelB;
	this->contadorI = contadorI;
	this->contadorJ = contadorJ;

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

int ArmazenaImagem::getR(){
	return pixelR;
}

void ArmazenaImagem::setR(int pixelR){
	this->pixelR = pixelR;
}

int ArmazenaImagem::getG(){
	return pixelG;
}

void ArmazenaImagem::setG(int pixelG){
	this->pixelG = pixelG;
}

int ArmazenaImagem::getB(){
	return pixelB;
}

void ArmazenaImagem::setB(int pixelB){
	this->pixelB = pixelB;
}

int ArmazenaImagem::getContadorI(){
	return contadorI;
}

void ArmazenaImagem::setContadorI(int contadorI){
	this->contadorI = contadorI;
}

int ArmazenaImagem::getContadorJ(){
	return contadorJ;
}

void ArmazenaImagem::setContadorJ(int contadorJ){
	this->contadorJ = contadorJ;
}

void ArmazenaImagem::armazenaDados(ofstream &arquivodesaida){

	ifstream arquivo1;
	string nomedoarquivo1;

	cout << "Digite a imagem que você deseja utilizar para aplicar o filtro: ";
	cin >> nomedoarquivo1;

	nomedoarquivo1 = "./doc/" + nomedoarquivo1 + ".ppm";

	arquivo1.open(nomedoarquivo1.c_str());

	if(!arquivo1.is_open())
	{

	cout << "Arquivo não encontrado! Saindo..." << endl;

	}
	else
	{
	string tipo, comentario, comentarioaux;
	int largura, altura, max_cor;

	getline(arquivo1,tipo);

	if(tipo != "P6")
	{
	cout << "Tipo de imagem inválida! Saindo..." << endl;
	return;
	}

	while(1)
	{

	getline(arquivo1,comentario);

	if(comentario[0] != '#')
	{
	cout << "Comentario armazenado: " << comentario << endl;
	//int tamanho;
	//int tamanho = strlen(comentario);
	int tamanho = comentario.length()+1;
	cout << "Tamanho do comentário: " << tamanho << endl;
	arquivo1.seekg(-tamanho,ios_base::cur);
	arquivo1 >> largura;
	cout << "Largura: " << largura << endl;
	arquivo1 >> altura;
	cout << "Altura: " << altura << endl;
	arquivo1 >> max_cor;
	cout << "Intensidade máxima: " << max_cor << endl;
	break;
	}

	}

	char r, g, b;

	setTipo(tipo);
	setLargura(largura);
	setAltura(altura);
	setMax_Cor(max_cor);


	string nomedoarquivo2;

	cout << "Digite o nome da nova imagem que foi alterada pelo filtro selecionado: " << endl;
	cin >> nomedoarquivo2;

	nomedoarquivo2 = "./doc/" + nomedoarquivo2 + ".ppm";

	while(nomedoarquivo2 == nomedoarquivo1)
	{
	cout << "Nome de arquivo inválido. Por favor, insira um novo nome: ";
	cin >> nomedoarquivo2;
	}

	arquivodesaida.open(nomedoarquivo2.c_str());

	//fazer condição para caso aconteça algum erro

	arquivodesaida << tipo << endl;
	arquivodesaida << largura << " " << altura << endl;
	arquivodesaida << max_cor << endl;


	int pixelR, pixelG, pixelB;
	int contadorI = 0, contadorJ = 0;
	int j, k;

	arquivo1.seekg(1,ios_base::cur);

	matrizR = new int*[altura];
	for(int i = 0; i < altura; i++)
	matrizR[i] = new int[largura];

	matrizG = new int*[altura];
	for(int i = 0; i < altura; i++)
	matrizG[i] = new int[largura];

	matrizB = new int*[altura];
	for(int i = 0; i < altura; i++)
	matrizB[i] = new int[largura];


	for(j = 0; j < altura; j++)
	{
		for(k = 0; k < largura; k++)
		{
		arquivo1.get(r);
		//if(r == '\n')
		arquivo1.get(g);
		//if(g == '\n')
		//arquivo1.get(g);
		arquivo1.get(b);
		//if(b == '\n')
		//arquivo1.get(b);
		pixelR = (int)r;
		pixelG = (int)g;
		pixelB = (int)b;
		matrizR[j][k] = (int)r;
		matrizG[j][k] = (int)g;
		matrizB[j][k] = (int)b;
		//setR(pixelR);
		//setG(pixelG);
		//setB(pixelB);

		//ArmazenaImagem *transfere = new ArmazenaImagem();
		//transfere->armazenaPixel(arquivodesaida);
		//contadorJ++;//coluna
		}
		//contadorI++;//linha

	}

	}

	armazenaPixel(arquivodesaida);

	arquivo1.close();
	arquivodesaida.close();
}

void ArmazenaImagem::armazenaPixel(ofstream &arquivodesaida){

	int Raux[altura][largura], Gaux[altura][largura], Baux[altura][largura]; 

	for(int i = 0; i < altura; i++)
	{
		for(int j = 0; j < largura; j++)
		{
		Raux[i][j] = matrizR[i][j];
		arquivodesaida << (char)Raux[i][j];
		Gaux[i][j] = matrizG[i][j];
		arquivodesaida << (char)Gaux[i][j];
		Baux[i][j] = matrizB[i][j];
		arquivodesaida << (char)Baux[i][j];
		}

	}

}

