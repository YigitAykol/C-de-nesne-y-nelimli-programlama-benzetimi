#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

typedef struct Bitki {
    Canli super;
} Bitki;

Bitki* BitkiOlustur(int id);
char* BitkiGorunum();

#endif
