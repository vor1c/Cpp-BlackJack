#ifndef HAND_H
#define HAND_H

#include "Karte.h"
#include <vector>
#include <algorithm>

class Hand {
private:
    std::vector<Karte> karten;

public:
    // Methode zum Hinzufügen einer einzelnen Karte zur Hand
    void hinzufuegen(Karte karte) {
        karten.push_back(karte);
        this->sortieren();
    }

    // Methode zum Hinzufügen einer Liste von Karten zur Hand
    void hinzufuegen(std::vector<Karte> kartenListe) {
        karten.insert(karten.end(), kartenListe.begin(), kartenListe.end());
        this->sortieren();
    }

    // Methode zum Sortieren der Karten in der Hand
    void sortieren() {
        std::sort(karten.begin(), karten.end());
    }

    // Methode zum Entfernen einer Karte aus der Hand anhand ihres Index
    Karte nehmenPos(int index) {
        Karte karte = karten[index];
        karten.erase(karten.begin() + index);
        return karte;
    }

    // Iterator-Methoden für den Zugriff auf die Karten in der Hand
    std::vector<Karte>::const_iterator begin() const {
        return karten.begin();
    }

    std::vector<Karte>::const_iterator end() const {
        return karten.end();
    }
};

#endif // HAND_H
