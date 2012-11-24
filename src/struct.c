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

void Insere(TipoItem x, TipoLista * Lista) { 
  Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
  Lista -> numeroPaginasLivres--;
}

void Retira(TipoApontador p, TipoLista *Lista) {
  TipoApontador aux;
  if (Vazia(*Lista) || p == NULL)  {
    printf(" Erro: Lista vazia ou posicao nao existe\n");
    return;
  }

  aux = p -> Prox;
  p -> Prox = aux -> Prox;
  
  if (p -> Prox == NULL)
    Lista -> Ultimo = p;
  
  // free(aux);
  Lista -> numeroPaginasLivres++;
}

void Pop(TipoLista * Lista) {
  if (Vazia(*Lista))  {
    printf(" Erro: Lista vazia ou posicao nao existe\n");
    return;
  }

  TipoApontador Aux;
  Aux = Lista->Primeiro -> Prox;

  Lista->Primeiro -> Prox = Aux -> Prox;
  // free(Aux);
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

TipoApontador Find(TipoLista * Lista, TipoItem pagina) {
  TipoApontador Aux;
  Aux = Lista->Primeiro->Prox;
  while (Aux != NULL)  {
    if (Aux -> Item.Chave == pagina.Chave) {  
      return Aux;
    }
    Aux = Aux -> Prox;
  }
  return Aux;
}

short PopEsp(TipoLista * Lista, TipoItem pagina) {
  if (Vazia(*Lista))  {
    printf(" Erro: Lista vazia ou posicao nao existe\n");
    return;
  }

  TipoApontador Aux, aux2;
  Aux = Lista->Primeiro->Prox;
  while (Aux != NULL)  {
    if (Aux -> Item.Chave == pagina.Chave) {
      aux2 = Aux -> Prox;
      Aux -> Prox = aux2 -> Prox;

      if (Aux -> Prox == NULL)
        Lista -> Ultimo = Aux;
      return 1;
    }
    Aux = Aux -> Prox;
  }
  Lista -> numeroPaginasLivres++;
  return 0;
}
