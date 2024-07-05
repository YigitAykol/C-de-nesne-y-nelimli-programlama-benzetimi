#include "Bocek.h"

char* BocekGorunum() {
    return "C";
}

void BocekSetId(Bocek* this, int id) {
    this->super.id = id;
    // Bocek için özel setId işlemleri burada yapılabilir
}

Bocek* BocekOlustur(int id) {
    Bocek* this = (Bocek*)malloc(sizeof(Bocek));
    this->super = *CanliOlustur(id);
    this->super.gorunum = BocekGorunum;
    this->super.setId = (void (*)(Canli*, int)) BocekSetId; // Polymorphism ile Bocek'e özel setId ataması
    return this;
}
