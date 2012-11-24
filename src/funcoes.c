// .c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "struct.h"

void fifo(TipoLista * memoria, TipoItem pagina) {
    // printf("%d\n", Find(memoria, pagina));
    if (!Find(memoria, pagina)){
        if (memoria->numeroPaginasLivres > 0) {
            Insere(pagina, memoria);
        } else {
            Pop(memoria);
            Insere(pagina, memoria);
        }
        memoria->misses++;
    }

}