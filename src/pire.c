#include "Pire.h"

char* PireGorunum() {
    return "P";
}

Pire* PireOlustur(int id) {
    Pire* this = (Pire*)malloc(sizeof(Pire));
    this->super.super = *CanliOlustur(id);
    this->super.super.gorunum = PireGorunum;
    return this;
}

