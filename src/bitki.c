#include "Bitki.h"

char* BitkiGorunum() {
    return "B";
}

Bitki* BitkiOlustur(int id) {
    Bitki* this = (Bitki*)malloc(sizeof(Bitki));
    this->super = *CanliOlustur(id);
    this->super.gorunum = BitkiGorunum;
    return this;
}
