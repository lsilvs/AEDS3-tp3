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
  x.acessos++;
}

void Retira(TipoApontador p, TipoLista * Lista) {
  TipoApontador aux;
  if (Vazia(*Lista) || p == NULL)  {
    printf(" Erro: Lista vazia ou posicao nao existe\n");
    return;
  }

  aux = p -> Prox;
  p -> Prox = aux -> Prox;
  
  if (p -> Prox == NULL)
    Lista -> Ultimo = p;
  
  free(aux);
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
  free(Aux);
  Lista -> numeroPaginasLivres++;
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

TipoApontador FindMinAcessos(TipoLista *Lista) {
    TipoApontador aux = Lista->Primeiro->Prox;
    TipoApontador auxProx = Lista->Primeiro->Prox;

    while(auxProx != NULL) {
        if (aux->Item.acessos <= auxProx->Item.acessos) {
          auxProx = auxProx->Prox;
        } else {
            aux = auxProx;
            auxProx = auxProx->Prox;
        }
    }

     return aux;
}
