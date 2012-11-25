// .h

#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include "struct.h"

void fifo(Tipo_Lista * memoria, struct tipo_elemento pagina);

void lfu(Tipo_Lista * memoria, struct tipo_elemento pagina);

void lru(Tipo_Lista * memoria, struct tipo_elemento pagina);

#endif