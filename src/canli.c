#include "Canli.h"

void setId(Canli* this, int id) {
    this->id = id;
}

char* gorunum() {
    return "Genel Canlı";
}

void CanliYoket(Canli* this) {
    if(this == NULL) return;
    free(this);
}

Canli* CanliOlustur(int id) {
    Canli* this = (Canli*)malloc(sizeof(Canli));
    this->id = id;
    this->setId = setId;
    this->gorunum = gorunum;
    this->yoket = CanliYoket;
    return this;
}