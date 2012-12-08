// .c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int lru(Tipo_Lista * memoria, struct tipo_elemento pagina) {
    int ret = -1;
    struct tipo_elemento * p;
    p = pesquisa(memoria, pagina.valor);
    if (p == NULL) {
        insere(memoria, pagina.valor);
        ordena(memoria->inicio, memoria->qtd);
    } else {
        ret = (memoria->qtd - p->acessos);
        elimina(memoria, p);
        insere(memoria, pagina.valor);
        ordena(memoria->inicio, memoria->qtd);
    }
    return ret;
}