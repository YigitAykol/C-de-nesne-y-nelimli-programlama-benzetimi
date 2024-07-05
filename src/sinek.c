#include "Sinek.h"

char* SinekGorunum() {
    return "S";
}

Sinek* SinekOlustur(int id) {
    Sinek* this = (Sinek*)malloc(sizeof(Sinek));
    this->super.super = *CanliOlustur(id);
    this->super.super.gorunum = SinekGorunum;
    return this;
}

