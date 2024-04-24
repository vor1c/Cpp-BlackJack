#include <iostream>
#include "Deck.h"
#include "Abhebestapel.h"
#include "Ablegestapel.h"

int main() {
    std::cout << "Sauaufdrahn" << std::endl;

    // geben
    Deck deck = Doppeldeutsch();
    deck.mischen();
    Abhebestapel abhebestapel;
    abhebestapel.hinzufuegen(deck.nehmen(deck.size()));
    //std::cout << abhebestapel.size() << " --> " << abhebestapel << std::endl;
    Ablegestapel ablegestapel;

    int anzahl_spieler = 5;
    int aktueller_spieler = 0;
    Karte karte{Symbol::SECHS, Farbe::EICHEL}; // Dummy-Karte
    do {
        aktueller_spieler = aktueller_spieler + 1;
        if (aktueller_spieler > anzahl_spieler)
            aktueller_spieler = 1;
        std::cout << "Spieler #" << aktueller_spieler << " karte nehmen";
        std::cin.ignore();
        karte = abhebestapel.nehmen();
        ablegestapel.hinzufuegen(karte);
        std::cout << "Oberste Karte: " << karte << std::endl;
    } while(karte.zahl() != Symbol::SAU);

    std::cout << "Spieler #" << aktueller_spieler << " hat verloren" << std::endl;

    return 0;
}