#include "Deck.h"
#include <random>
#include <chrono>
#include <algorithm>
Deck::Deck(std::vector<Farbe> farben, std::vector<Symbol> werte) {
    for(Farbe farbe : farben) {
        for(Symbol symbol : werte) {
            this->push_back(Karte {symbol, farbe});
        }
    }
}


void Deck::mischen() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(begin(), end(), std::default_random_engine(seed));
}