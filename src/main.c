/*
*	Sistema de Memória Virtual (SMV)
*		Autor: Lucas Silvestre (2010054665)
*		Data: 24/11/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "struct.h"

int main(int argc, char *argv[]) {
	// Declara as variáveis
	char * inputFileName = argv[1];
	char * outputFileName = argv[2];
	int i, j, numeroInstancias, tamanhoBytesMemoriaFisica, tamanhoBytesPagina, numeroAcessos, valorAcessado;
	
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

		for (j = 0; i < numeroAcessos; ++i) {
			fscanf(inputFileOpen, "%d", &valorAcessado);
			printf("%d\n", valorAcessado >> (tamanhoBytesMemoriaFisica/tamanhoBytesPagina));
		}

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