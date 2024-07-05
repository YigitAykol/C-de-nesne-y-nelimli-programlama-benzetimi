#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

typedef struct Bocek {
    Canli super;
    
} Bocek;

Bocek* BocekOlustur(int id);
char* BocekGorunum();
void BocekSetId(Bocek* this, int id);//

#endif
