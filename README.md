Image filter
_________________________________________________________________________
Instruções para o uso do EP1
-------------------------------------------------------------------------

Para a inicialização do programa, será feito o uso do Makefile.


_________________________________________________________________________
Passo 1: Limpando os arquivos objeto
-------------------------------------------------------------------------

$ make clean

_________________________________________________________________________
Passo 2: Compilando o programa
-------------------------------------------------------------------------

$ make

_________________________________________________________________________
Passo 3: Executando o programa
-------------------------------------------------------------------------

$ make run


_________________________________________________________________________

Instruções para pós-execução 

-------------------------------------------------------------------------

- Para a abertura da imagem, só funciona sem a extensão da imagem. Por exemplo:

	> Para abertura da imagem unb.ppm, só é necessário que escreva o nome:
		
		unb, sem a extensão da imagem.

- O código está auto-explicativo, não em sua estrutura, mas para a sua execução.

- Para a procura da imagem e para a criação da nova imagem, é necessário apenas
 digitar o nome da imagem, sem o seu tipo de extensão, ou seja:
	> Digite a imagem que você deseja utilizar para aplicar o filtro: unb

	(imagem a ser aberta para realização das operações será a imagem unb.ppm)

	> Válido também para a criação da nova imagem.

- Primeiramente, caso o usuário não respeite as instruções dadas no início da 
execução do programa, o programa deverá corrigir alguns erros, dependendo da 
gravidade dos erros apresentados.

- Caso o usuário faça o procedimento correto, o projeto vai ser concluido com
sucesso.

- O filtro de média possui uma característica diferente da solicitada pelo 
enunciado do EP1. O filtro tem a capacidade de aplicar uma máscara de vários
tamanhos, só é necessário que o usuário digite um valor válido para o cálculo.

- Os arquivos de imagem se encontram na pasta 'doc' relativa ao EP1.


-------------------------------------------------------------------------
