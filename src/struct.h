// .h

#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef int TipoChave;

typedef struct {
  int Chave;
  int acessos;
} TipoItem;

typedef struct TipoCelula * TipoApontador;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
  int numeroPaginas;
  int numeroPaginasLivres;
  int misses;
} TipoLista;

/* ========================================================================= */

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

void Insere(TipoItem x, TipoLista * Lista);

void InsereOrdenado(TipoItem x, TipoLista * Lista);

void Retira(TipoApontador p, TipoLista * Lista);

void Imprime(TipoLista Lista);

TipoApontador Find(TipoLista * Lista, TipoItem pagina);

TipoApontador FindMinAcessos(TipoLista *Lista);

#endif