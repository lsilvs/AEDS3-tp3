// .h

#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


struct tipo_elemento {
  int valor;  
  int acessos;
  struct tipo_elemento *proximo;
  struct tipo_elemento *anterior;
};

typedef struct {
  int qtd;
  struct tipo_elemento * fim, * inicio;
  int numeroPaginasLivres;
  int misses;
} Tipo_Lista;


void inicializa(Tipo_Lista * a);

int isVazio(Tipo_Lista * a);

void mostra(struct tipo_elemento * tmp, int funcionamento);

struct tipo_elemento * pesquisa(Tipo_Lista * a, int alvo);

void desaloca_lista(Tipo_Lista * a);

void elimina(Tipo_Lista * a, struct tipo_elemento * ponteiro_alvo);

void insere(Tipo_Lista * a, int v);

void ordena_by_acessos (struct tipo_elemento * e);

#endif