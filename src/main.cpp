#include "armazenaimagem.hpp"

int main (){


	cout << "\nBem vindo a tela inicial para aplicação de filtro em imagens! " << endl;
	cout << "\n\n No momento temos apenas os seguintes filtros: " << endl;
	cout << "\n\n\n(1) - Negativo\n(2) - Polarizado\n(3) - Preto e Branco\n(4) - Média\n(0) - Sair\n" << endl;

	int opcao = 0;

	cin >> opcao;

	ArmazenaImagem *armazena = new ArmazenaImagem();

	armazena->modificaImagem();












	return 0;

}
