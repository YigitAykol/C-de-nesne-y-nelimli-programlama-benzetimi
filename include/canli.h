#ifndef CANLI_H
#define CANLI_H

#include <stdio.h>
#include <stdlib.h>



typedef struct Canli {
    int id;
    

    void (*setId)(struct Canli*, int);
    char* (*gorunum)();
    void (*yoket)(struct Canli*);
    struct Canli* next;
} Canli;


Canli* CanliOlustur(int id);
void CanliYoket( Canli *this);

#endif
