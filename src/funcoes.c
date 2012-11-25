// .c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void fifo(Tipo_Lista * memoria, struct tipo_elemento pagina) {
    struct tipo_elemento * p;
    p = pesquisa(memoria, pagina.valor);
    if (p == NULL) {
        if (memoria->numeroPaginasLivres > 0) {
            insere(memoria, pagina.valor);
        } else {
            elimina(memoria, memoria->fim);
            insere(memoria, pagina.valor);
        }
        memoria->misses++;
    }
}

void lru(Tipo_Lista * memoria, struct tipo_elemento pagina) {
    struct tipo_elemento * p;
    p = (struct tipo_elemento *) malloc (sizeof(struct tipo_elemento));
    p = pesquisa(memoria, pagina.valor);
    if (p == NULL) {
        if (memoria->numeroPaginasLivres > 0) {
            insere(memoria, pagina.valor);
        } else {
            elimina(memoria, memoria->fim);
            insere(memoria, pagina.valor);
        }
        memoria->misses++;
    } else {
        elimina(memoria, p);
        insere(memoria, pagina.valor);
    }
}

void lfu(Tipo_Lista * memoria, struct tipo_elemento pagina) {
    struct tipo_elemento * p;
    p = (struct tipo_elemento *) malloc (sizeof(struct tipo_elemento));
    p = pesquisa(memoria, pagina.valor);
    if (p == NULL) {
        if (memoria->numeroPaginasLivres > 0) {
            insere(memoria, pagina.valor);
        } else {
            elimina(memoria, memoria->inicio);
            insere(memoria, pagina.valor);
        }
        memoria->misses++;
    } else {
        p->acessos++;
        ordenaByAcessos(memoria);
    }
}
