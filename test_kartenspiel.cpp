#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include "Karte.h"
#include "Deck.h"
#include "Hand.h"

// Funktion zur Berechnung der Punktzahl einer Hand
int punktzahlBerechnen(const Hand& hand) {
    int summe = 0;
    int asse = 0;

    // Iteriere über die Karten in der Hand
    for (const auto& karte : hand) {
        // Zugriff auf den Wert jeder Karte
        int wert = karte.wert(); // Verwenden der wert()-Methode der Karte-Klasse

        // Behandlung von Assen
        if (wert == 11) {
            asse++;
            summe += 11; // Ass wird vorerst als 11 gezählt
        }
            // Behandlung anderer Karten
        else {
            summe += wert;
        }
    }

    // Korrektur, falls Ass als 11 zu viel wäre
    while (summe > 21 && asse > 0) {
        summe -= 10;
        asse--;
    }

    return summe;
}

std::string handToString(const Hand& hand, bool zeigeAlleKarten) {
    std::string result;
    bool ersteKarte = true;
    for (const auto& karte : hand) {
        if (!zeigeAlleKarten && ersteKarte) {
            result += "Verdeckt ";
            ersteKarte = false;
        } else {
            result += Karte::karteToString(karte) + " ";
        }
    }
    return result;
}

// Funktion zur Berechnung der Hand des Dealers
void dealerSpielt(Hand& dealerHand, Deck& deck) {
    // Dealer zieht Karten, solange die Punktzahl kleiner als 17 ist
    while (punktzahlBerechnen(dealerHand) < 17) {
        dealerHand.hinzufuegen(deck.nehmen());
    }
}

std::string punktzahlZuString(int punkte) {
    if (punkte > 21) {
        return " (Bust)";
    } else {
        return " (Punktzahl: " + std::to_string(punkte) + ")";
    }
}

int main() {
    std::cout << "Willkommen beim Blackjack!" << std::endl;

    // Initialisierung des Decks und Mischens
    Franzoesisch deck;
    deck.mischen();

    // Spieler und Dealer initialisieren
    Hand spielerHand, dealerHand;
    spielerHand.hinzufuegen(deck.nehmen());
    dealerHand.hinzufuegen(deck.nehmen());
    spielerHand.hinzufuegen(deck.nehmen());
    dealerHand.hinzufuegen(deck.nehmen());

    std::cout << "Deine Hand: " << handToString(spielerHand, true) << punktzahlZuString(punktzahlBerechnen(spielerHand)) << std::endl;
    std::cout << "Dealer zeigt: " << handToString(dealerHand, false) << std::endl;

    // Spieler zieht Karten
    while (true) {
        char choice;
        std::cout << "Moechtest du eine weitere Karte ziehen? (j/n): ";
        std::cin >> choice;
        if (choice == 'j') {
            spielerHand.hinzufuegen(deck.nehmen());
            std::cout << "Deine Hand: " << handToString(spielerHand, true) << punktzahlZuString(punktzahlBerechnen(spielerHand)) << std::endl;
            if (punktzahlBerechnen(spielerHand) > 21) {
                std::cout << "Du hast verloren! (ueber 21)" << std::endl;
                return 0;
            }
        } else {
            break;
        }
    }

    // Dealer spielt
    dealerSpielt(dealerHand, deck);

    std::cout << "Dealer's Hand: " << handToString(dealerHand, true) << punktzahlZuString(punktzahlBerechnen(dealerHand)) << std::endl;

    // Gewinner ermitteln
    int spielerPunkte = punktzahlBerechnen(spielerHand);
    int dealerPunkte = punktzahlBerechnen(dealerHand);
    if (dealerPunkte > 21 || spielerPunkte > dealerPunkte) {
        std::cout << "Herzlichen Glueckwunsch! Du hast gewonnen!" << std::endl;
    } else if (dealerPunkte > spielerPunkte) {
        std::cout << "Dealer gewinnt!" << std::endl;
    } else {
        std::cout << "Unentschieden!" << std::endl;
    }

    return 0;
}
