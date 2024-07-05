#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

typedef struct Sinek {
    Bocek super;
} Sinek;

Sinek* SinekOlustur(int id);
char* SinekGorunum();

#endif
