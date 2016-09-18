#include "armazenaimagem.hpp"
#include "negativo.hpp"

int main (){


	cout << "\nBem vindo a tela inicial para aplicação de filtro em imagens! " << endl;
	cout << "\n\n No momento temos apenas os seguintes filtros: " << endl;
	cout << "\n\n\n(1) - Normal\n(2) - Negativo\n(3) - Polarizado\n(4) - Preto e Branco\n(5) - Média\n(0) - Sair\n" << endl;

	int opcao = 0;

	cin >> opcao;

	ArmazenaImagem *armazena = new ArmazenaImagem();
	Negativo *negativo = new Negativo();

	ofstream arquivodesaida;

	if(opcao == 0)
	armazena->armazenaDados(arquivodesaida);

	if(opcao == 2)
	negativo->armazenaDados(arquivodesaida);




	return 0;

}
