#ifndef INC_4AHEL_GR2_KARTENSPIEL_H
#define INC_4AHEL_GR2_KARTENSPIEL_H

#include <deque>
#include <vector>
#include <iostream>
#include "Karte.h"

class Kartenspiel: protected std::deque<Karte> {
public:
    Kartenspiel() = default;

    using std::deque<Karte>::size;
    using std::deque<Karte>::empty;

    std::vector<Karte> alleKarten();

    void mischen();
    void sortieren();

    Karte nehmen();
    std::vector<Karte> nehmen(unsigned int n);

    virtual void hinzufuegen(Karte karte);
    virtual void hinzufuegen(std::vector<Karte> karten);
};

std::ostream &operator<<(std::ostream &, std::vector<Karte>);
std::ostream &operator<<(std::ostream &, Kartenspiel &);



#endif //INC_4AHEL_GR2_KARTENSPIEL_H
