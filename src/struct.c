// .c

#include "struct.h"


void inicializa (Tipo_Lista * a) {
  a->qtd = 0;
  a->fim = NULL;
  a->inicio = NULL;
  a->misses = 0;
}

int isVazio(Tipo_Lista * a) {
  return a->qtd;
}

void mostra (struct tipo_elemento * tmp, int funcionamento)
{
          
     while (tmp != NULL ) { 

         printf ("Valor=%d\n",tmp->valor);
   if (funcionamento==0) return;
  tmp = tmp->proximo;
   
     }

}

struct tipo_elemento * pesquisa (Tipo_Lista * a, int alvo ) {
    struct tipo_elemento * tmp;
    tmp = a->inicio;
    while (tmp != NULL ) { 
      if (alvo == tmp->valor) {
        return (tmp);
      }
      tmp = tmp->proximo; 
    }
    return (NULL);
}

void desaloca_lista(Tipo_Lista * a) {
  struct tipo_elemento * tmp, * aux;
  tmp = a->inicio;
  while (tmp != NULL) {
    aux = tmp->proximo;
    free(tmp);
    tmp = aux;
  }
}

void elimina (Tipo_Lista * a, struct tipo_elemento * ponteiro_alvo) {
  
  if (ponteiro_alvo->anterior == NULL && ponteiro_alvo->proximo == NULL) {
    a->fim = NULL;
    a->inicio = NULL;
  } else if (ponteiro_alvo->anterior == NULL) {   // o elemento eh o primeiro
    a->inicio = ponteiro_alvo->proximo;
    ponteiro_alvo->proximo->anterior = NULL;
  } else if (ponteiro_alvo->proximo == NULL) { // o elemento eh o ultimo
    a->fim = ponteiro_alvo->anterior;
    ponteiro_alvo->anterior->proximo = NULL;
  } else {
    ponteiro_alvo->anterior->proximo = ponteiro_alvo->proximo;
    ponteiro_alvo->proximo->anterior = ponteiro_alvo->anterior;
  }

  a->qtd--;
  a->numeroPaginasLivres++;
  free(ponteiro_alvo);
}

void insere (Tipo_Lista * a, int v) {
  struct tipo_elemento * x;
  x = (struct tipo_elemento *) malloc (sizeof(struct tipo_elemento));

  if (a->inicio == NULL) {
    a->inicio = x;
    a->fim = x;
    x->proximo = NULL;
  } else {
    x->proximo = a->inicio;
    a->inicio->anterior=x;
    a->inicio=x;
  }

  x->anterior = NULL; 
  x->valor = v;
  a->qtd++;
  a->numeroPaginasLivres--;
}


void ordenaByAcessos(Tipo_Lista * a) {
  struct tipo_elemento * aux1, * aux2, * aux3;
  aux1 = a->inicio;
  aux2 = aux1->proximo;

  while (aux2 != NULL) {
    if (aux1->acessos > aux2->acessos) {
      aux3 = aux1;
      aux1 = aux2;
      aux2 = aux3;
    }

    aux1 = aux2;
    aux2 = aux2->proximo;
  }

}


