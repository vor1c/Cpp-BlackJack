#include "Abhebestapel.h"
#include <random>
#include <algorithm>

void Abhebestapel::hinzufuegen(std::vector<Karte> karten) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(karten.begin(), karten.end(), g);
    Kartenspiel::hinzufuegen(karten);
}
