/*
*	Sistema de Memória Virtual (SMV)
*		Autor: Lucas Silvestre (2010054665)
*		Data: 24/11/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "funcoes.h"


int main(int argc, char *argv[]) {
	// Declara as variáveis
	char * inputFileName = argv[1];
	char * outputFileName = argv[2];
	int i, j, numeroInstancias, tamanhoBytesMemoriaFisica, tamanhoBytesPagina, numeroAcessos, 
		valorAcessado, numeroPaginas;
	TipoItem paginaAtual;

	// Abrir arquivo de entrada
	FILE * inputFileOpen;
	if ((inputFileOpen = fopen(inputFileName, "r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	}

	// Abrir arquivo de saída
	FILE * outputFileOpen;
	if ((outputFileOpen = fopen(outputFileName, "w")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	}

	// Lê o número de instâncias
	fscanf(inputFileOpen, "%d", &numeroInstancias);

	for(i = 0; i < numeroInstancias; i++) {
		// Lê a entrada
		fscanf(inputFileOpen, "%d", &tamanhoBytesMemoriaFisica);
		fscanf(inputFileOpen, "%d", &tamanhoBytesPagina);
		fscanf(inputFileOpen, "%d", &numeroAcessos);

		numeroPaginas = tamanhoBytesMemoriaFisica/tamanhoBytesPagina;

		TipoLista * fifoList = (TipoLista *) malloc(sizeof(TipoLista));
		FLVazia(fifoList);
		fifoList->misses = 0;
		fifoList->numeroPaginas = numeroPaginas;
		fifoList->numeroPaginasLivres = numeroPaginas;

		TipoLista * lruList = (TipoLista *) malloc(sizeof(TipoLista));
		FLVazia(lruList);
		lruList->misses = 0;
		lruList->numeroPaginas = numeroPaginas;
		lruList->numeroPaginasLivres = numeroPaginas;

		TipoLista * lfuList = (TipoLista *) malloc(sizeof(TipoLista));
		FLVazia(lfuList);
		lfuList->misses = 0;
		lfuList->numeroPaginas = numeroPaginas;
		lfuList->numeroPaginasLivres = numeroPaginas;

		for (j = 0; i < numeroAcessos; ++i) {
			fscanf(inputFileOpen, "%d", &valorAcessado);
			paginaAtual.Chave = valorAcessado >> numeroPaginas;

			fifo(fifoList, paginaAtual);
			lru(lruList, paginaAtual);
			// lfu(lfuList, paginaAtual);

		}

		printf("%d\n", fifoList->misses);
		printf("%d\n", lruList->misses);
		// printf("%d\n", lfuList->misses);
	}


	// Retorna 0 se conseguiu fechar o arquivo com sucesso
	if(fclose(inputFileOpen) != 0) {
		printf("Erro ao tentar fechar o arquivo %s\n", inputFileName);
	}

	if(fclose(outputFileOpen) != 0) {
		printf("Erro ao tentar fechar o arquivo %s\n", outputFileName);
	}

	return 0;
}