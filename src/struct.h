// .h

#include <stdlib.h>
#include <stdio.h>

typedef int TipoChave;

typedef struct {
  int Chave;
} TipoItem;

typedef struct TipoCelula *TipoApontador;

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

void Insere(TipoItem x, TipoLista *Lista);

void Retira(TipoApontador p, TipoLista * Lista, TipoItem *Item);

void Imprime(TipoLista Lista);

short Find(TipoLista * Lista, TipoItem pagina);