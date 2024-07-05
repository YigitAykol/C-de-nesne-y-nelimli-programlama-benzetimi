#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

typedef struct Pire {
    Bocek super;
} Pire;

Pire* PireOlustur(int id);
char* PireGorunum();

#endif
