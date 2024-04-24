#ifndef INC_4AHEL_GR2_ABHEBESTAPEL_H
#define INC_4AHEL_GR2_ABHEBESTAPEL_H

#include "Kartenspiel.h"

class Abhebestapel: public Kartenspiel {
public:
    void hinzufuegen(std::vector<Karte> karten) override;
};


#endif //INC_4AHEL_GR2_ABHEBESTAPEL_H
