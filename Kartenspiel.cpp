#include "Kartenspiel.h"
#include <random>
#include <algorithm>
#include <stdexcept>

std::vector<Karte> Kartenspiel::alleKarten() {
    return std::vector<Karte>{this->begin(), this->end()};
}

void Kartenspiel::mischen() {
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(this->begin(), this->end(), g);
}

void Kartenspiel::sortieren() {
    std::sort(this->begin(), this->end());
}

Karte Kartenspiel::nehmen() {
    if (this->empty()) {
        throw std::out_of_range("Nicht genügend Karten!");
    }
    Karte karte = this->front();
    this->pop_front();
    return karte;
}

std::vector<Karte> Kartenspiel::nehmen(unsigned int n) {
    if (n > this->size()) {
        throw std::out_of_range("Nicht genügend Karten!");
    }
    std::vector<Karte> karten(this->begin(), this->begin()+n);
    this->erase(this->begin(), this->begin()+n);
    return karten;
}

void Kartenspiel::hinzufuegen(Karte karte) {
    this->push_back(karte);
}

void Kartenspiel::hinzufuegen(std::vector<Karte> karten) {
    this->insert(this->end(), karten.begin(), karten.end());
}

std::ostream &operator<<(std::ostream &os, std::vector<Karte> karten) {
    for (Karte karte : karten) {
        os << karte << ", ";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, Kartenspiel &kartenspiel) {
    os << kartenspiel.alleKarten();
    return os;
}
