#include "armazenaimagem.hpp"
#include "negativo.hpp"
#include "polarizado.hpp"
#include "pretoebranco.hpp"
#include "media3x3.hpp"

int main (){


	cout << "\nBem vindo a tela inicial para aplicação de filtro em imagens! " << endl;
	cout << "\n\n No momento temos apenas os seguintes filtros: " << endl;
	cout << "\n\n\n(1) - Normal\n(2) - Negativo\n(3) - Polarizado\n(4) - Preto e Branco\n(5) - Média 3 x 3\n(6) - Média 5 x 5\n(7) - Média 7 x 7\n(0) - Sair\n" << endl;

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


	return 0;

}
