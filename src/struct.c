// .c

#include "struct.h"

void FLVazia(TipoLista *Lista) {
  Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
}

int Vazia(TipoLista Lista) { 
  return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) { 
  Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
  Lista -> numeroPaginasLivres--;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p -> Prox == NULL)  {
    printf(" Erro: Lista vazia ou posicao nao existe\n");
    return;
  }

  q = p -> Prox;
  *Item = q -> Item;
  p -> Prox = q -> Prox;
  if (p -> Prox == NULL) Lista -> Ultimo = p;
  free(q);
  Lista -> numeroPaginasLivres++;
}

void Pop(TipoLista * Lista) {
  // if (Vazia(*Lista))  {
  //   printf(" Erro: Lista vazia ou posicao nao existe\n");
  //   return;
  // }

  TipoApontador Aux;
  Aux = Lista->Primeiro -> Prox;

  Lista->Primeiro -> Prox = Aux -> Prox;
  free(Aux);
  Lista -> numeroPaginasLivres++;
}

void Imprime(TipoLista Lista) { 
  TipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL)  {
    printf("%d\n", Aux -> Item.Chave);
    Aux = Aux -> Prox;
  }
}

short Find(TipoLista * Lista, TipoItem pagina) { 
  TipoApontador Aux;
  Aux = Lista->Primeiro->Prox;
  while (Aux != NULL)  {
    // printf("%d\n", Aux -> Item.Chave);
    if (Aux -> Item.Chave == pagina.Chave) {
      return 1;
    }
    Aux = Aux -> Prox;
  }
  return 0;
}
