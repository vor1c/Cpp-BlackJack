#ifndef INC_4AHEL_GR2_ABLEGESTAPEL_H
#define INC_4AHEL_GR2_ABLEGESTAPEL_H

#include "Kartenspiel.h"

class Ablegestapel: public Kartenspiel {
public:
    Karte anschauen() { return this->front(); };
    void hinzufuegen(Karte karte) override { this->push_front(karte); };
    void hinzufuegen(std::vector<Karte> karten) override {
        this->insert(this->begin(), karten.rbegin(), karten.rend());
    }
};


#endif //INC_4AHEL_GR2_ABLEGESTAPEL_H
