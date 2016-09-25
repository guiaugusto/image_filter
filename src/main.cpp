#include "armazenaimagem.hpp"
#include "negativo.hpp"
#include "polarizado.hpp"
#include "pretoebranco.hpp"
#include "media3x3.hpp"

int main (){


	cout << "\n\n------------------------------MENU DE OPERAÇÕES------------------------------" << endl;
	cout << "\n\n Escolha o filtro desejado: " << endl;
	cout << "\n\n\n\t(1) - Normal\n\t(2) - Negativo\n\t(3) - Polarizado\n\t(4) - Preto e Branco\n\t(5) - Média\n\t(0) - Sair\n" << endl;
	cout << "\n\n-----------------------------------------------------------------------------" << endl;
	int opcao = 0;
	cout << "Escolha uma opção: ";
	cin >> opcao;

	ArmazenaImagem *armazena = new ArmazenaImagem();
	Negativo *negativo = new Negativo();
	Polarizado *polarizado = new Polarizado();
	PretoeBranco *pretoebranco = new PretoeBranco();
	Media3x3 *media3x3 = new Media3x3();

	ofstream arquivodesaida;

	if(opcao == 1)
	armazena->armazenaDados(arquivodesaida);

	if(opcao == 2)
	negativo->armazenaDados(arquivodesaida);

	if(opcao == 3)
	polarizado->armazenaDados(arquivodesaida);

	if(opcao == 4)
	pretoebranco->armazenaDados(arquivodesaida);

	if(opcao == 5)
	media3x3->armazenaDados(arquivodesaida);

	if(opcao == 0){
	system("clear");
	cout << "\n\nSaindo do programa...\n\n" << endl;
	}
	return 0;

}
