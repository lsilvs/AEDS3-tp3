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

void mostra (struct tipo_elemento * tmp, int funcionamento) {
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
    a->qtd--;
    a->numeroPaginasLivres++;
  }
  free(a);
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
  struct tipo_elemento * aux;
  aux = (struct tipo_elemento *) malloc (sizeof(struct tipo_elemento));

  if (a->inicio == NULL) {
    a->inicio = aux;
    a->fim = aux;
    aux->proximo = NULL;
  } else {
    aux->proximo = a->inicio;
    a->inicio->anterior = aux;
    a->inicio = aux;
  }

  aux->anterior = NULL; 
  aux->valor = v;
  aux->acessos = 1;
  a->qtd++;
  a->numeroPaginasLivres--;
}

void ordena_by_acessos (struct tipo_elemento * e) {
  struct tipo_elemento * aux = (struct tipo_elemento *) malloc ( sizeof (struct tipo_elemento));
  if (e->proximo != NULL) {
    if ((e->acessos) == (e->proximo->acessos)) {
      if ((e->valor) > (e->proximo->valor)) {
        //copia elemento para auxiliar
        aux->valor = e->valor;
        aux->acessos = e->acessos;

        //copia proximo para elemento
        e->valor = e->proximo->valor;
        e->acessos = e->proximo->acessos;

        //copia elemento para proximo
        e->proximo->valor = aux->valor;
        e->proximo->acessos = aux->acessos;
      }
    } else if ((e->acessos) > (e->proximo->acessos)) {
      //copia elemento para auxiliar
      aux->valor = e->valor;
      aux->acessos = e->acessos;

      //copia proximo para elemento
      e->valor = e->proximo->valor;
      e->acessos = e->proximo->acessos;

      //copia elemento para proximo
      e->proximo->valor = aux->valor;
      e->proximo->acessos = aux->acessos;
    }
    ordena_by_acessos(e->proximo);
  }
  free(aux);
}
