// .c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

// invetorna o meior inteiro dentre os dois parâmetros
inline int maior(int a, int b) {
    return a >= b ? a : b;
}

// Calcula o número mínimo de caracteres necessários
// para transformar dada palavra em um palíndromo
int prog_din(char * palavra) {
	int j, k, l;
	int array[2][MAX_CARACTERES];
	int length = strlen(palavra);

    // Seta os valores iniciais em zero para o array
    memset(array, 0, sizeof(array));

    // Percorre a palavra de trás para frente
    for(j = length-1; j >= 0; j--) {
        char ch = palavra[j];

        // Percorre a palavra em seu sentido normal
        for (k = 0; k < length; k++) {
            if (ch == palavra[k]) {
                array[1][k+1] = array[0][k] + 1;
            } else {
            	array[1][k+1] = maior(array[1][k], array[0][k+1]);
            }
        }

        // Salva na posição zero do array os dados calculados
        for (l = 0; l <= length; l++) {
            array[0][l] = array[1][l];
        }
    }

    // invetorna o tamanho da palavra subitraindo-se 
    // o maior palíndromo encontrado
    return (length - array[1][k]);
}


// invetorna a posição em palavra_inv onde possui o char caracter
inline int ocor_inv(char caracter, char * palavra_inv, int inv) {
    int i = inv + 1;
    int len = strlen(palavra_inv);

    for (i; i < len; i++) {
        if (caracter == palavra_inv[i]) {
            return(i);
        }
    }
    return(-1);
}

// Calcula a solução, não necessariamente ótima,
// para encontrar número de caracteres necessários
// para transformar dada palavra em um palíndromo
int prog_gul(char * palavra) {
    int i, j, orig, inv = -1, fix = 0, aux1, aux2;
    int length = strlen(palavra);
    char * palavra_inv = malloc(sizeof(char) * length+1);

    // Inverte a palavra original
    for (i = length - 1, j = 0; i >= 0; i--, j++) {
        palavra_inv[j] = palavra[i];
    }
    palavra_inv[length] = '\0';

    // Percorre todo as letras da palavra original
    for (orig = 0; orig < length; orig++) {
        // Enquanto não chegar ao final da palavra invertida
        if (inv < length - 1) {
            // Enquanto não chegar ao final da palavra original
            if (orig < length - 2) {
                // Compara os caracteres da palavra original dois a dois
                // com a palavra invertida
                aux1 = ocor_inv(palavra[orig], palavra_inv, inv);
                aux2 = ocor_inv(palavra[orig+1], palavra_inv, inv);

                // Caso ambos caracteres são iguais
                if (aux1 > inv && aux2 > inv) {
                    if (aux1 < aux2){
                        inv = aux1;
                        fix += 1;
                    } else if (aux1 > aux2) {
                        inv = aux2;
                        fix += 1;
                        orig++;
                    } else if (aux1 == aux2) {
                        inv = aux1;
                        fix += 1;
                    }
                // Caso somente o primeiro caracter seja igual
                } else if (aux1 > inv) {
                    inv = aux1;
                    fix += 1;
                // Caso somente o segundo caracter seja igual
                } else if (aux2 > inv) {
                    inv = aux2;
                    fix += 1;
                    orig++;
                }
            } else {
                aux1 = ocor_inv(palavra[orig], palavra_inv, inv);
                if(aux1 != -1) {
                    inv = aux1;
                    fix += 1;
                }
            }
        } else {
            break;
        }

    }
    free (palavra_inv);
    return (length - fix);
}