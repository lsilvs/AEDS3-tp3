// .c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void fifo(TipoLista * memoria, TipoItem pagina) {
    TipoApontador p = NULL;
    p = Find(memoria, pagina);
    if (p == NULL) {
        if (memoria->numeroPaginasLivres > 0) {
            Insere(pagina, memoria);
        } else {
            Pop(memoria);
            Insere(pagina, memoria);
        }
        memoria->misses++;
    }
}

void lru(TipoLista * memoria, TipoItem pagina) {
    TipoApontador p = NULL;
    p = Find(memoria, pagina);
    if (p == NULL) {
        if (memoria->numeroPaginasLivres > 0) {
            Insere(pagina, memoria);
        } else {
            Pop(memoria);
            Insere(pagina, memoria);
        }
        memoria->misses++;
    } else {
        if (p->Prox != NULL) {
            Retira(p, memoria);
            Insere(pagina, memoria);
        }
    }
}

void lfu(TipoLista * memoria, TipoItem pagina) {
    TipoApontador p = NULL;
    p = Find(memoria, pagina);
    if (p == NULL) {
        if (memoria->numeroPaginasLivres > 0) {
            Insere(pagina, memoria);
        } else {
            Pop(memoria);
            Insere(pagina, memoria);
        }
        memoria->misses++;
    } else {
        p = FindMinAcessos(memoria);
        // Pode gerar problemas futuros
        if (p->Prox != NULL){
            Retira(p, memoria);
            Insere(pagina, memoria);
        }
    }
}
