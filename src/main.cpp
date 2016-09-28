#include "armazenaimagem.hpp"
#include "negativo.hpp"
#include "polarizado.hpp"
#include "pretoebranco.hpp"
#include "media.hpp"

int main (){

	system("clear");
	cout << "\n\n------------------------------MENU DE OPERAÇÕES------------------------------" << endl;
	cout << "\n \tESCOLHA O FILTRO DESEJADO PARA SER APLICADO EM UMA IMAGEM:" << endl;
	cout << "\n-----------------------------------------------------------------------------" << endl;
	cout << "\n\n\t(1) - Normal\n\n\t(2) - Negativo\n\n\t(3) - Polarizado\n\n\t(4) - Preto e Branco\n\n\t(5) - Média\n\n\t(6) - Sair\n\n" << endl;
	cout << "\n-----------------------------------------------------------------------------" << endl;
	string escolha;
	int opcao = 0;
	cout << "Escolha uma opção: ";

	do{
	getline(cin,escolha);

	if(isdigit(escolha[0]))
	{
	opcao = stoi(escolha);
	}

	if(opcao < 1 || opcao > 6)
	cout << "Opção inválida! Digite uma nova opção: ";

	}while(opcao < 1 || opcao > 6);

	ArmazenaImagem *armazena = new ArmazenaImagem();
	Negativo *negativo = new Negativo();
	Polarizado *polarizado = new Polarizado();
	PretoeBranco *pretoebranco = new PretoeBranco();
	Media *media = new Media();

	ofstream arquivodesaida;

	if(opcao == 1){
	armazena->armazenaDados(arquivodesaida);
	}

	if(opcao == 2){
	negativo->armazenaDados(arquivodesaida);
	}

	if(opcao == 3){
	polarizado->armazenaDados(arquivodesaida);
	}

	if(opcao == 4){
	pretoebranco->armazenaDados(arquivodesaida);
	}

	if(opcao == 5){
	media->armazenaDados(arquivodesaida);
	}

	if(opcao == 6){
	cout << "Saindo...\n\n\n" << endl;
	}
	return 0;

}
