#ifndef INC_4AHEL_GR2_DECK_H
#define INC_4AHEL_GR2_DECK_H

#include "Kartenspiel.h"
#include <vector>

class Deck: public Kartenspiel {

public:
    Deck(std::vector<Farbe> farben, std::vector<Symbol> werte);

    void mischen();
};

class Franzoesisch: public Deck {
public:
    Franzoesisch() : Deck(
            std::vector<Farbe> {Farbe::HERZ, Farbe::PIK, Farbe::KREUZ, Farbe::KARO},
            std::vector<Symbol> {Symbol::Zwei, Symbol::Drei, Symbol::Vier, Symbol::Fuenf, Symbol::Sechs, Symbol::Sieben, Symbol::Acht, Symbol::Neun, Symbol::Zehn, Symbol::Junge, Symbol::Koenigin, Symbol::Koenig, Symbol::Ass}
            ) {};
};


#endif //INC_4AHEL_GR2_DECK_H
