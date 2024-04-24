#ifndef KARTE_H
#define KARTE_H

#include <iostream>
#include <string>

// Definition der Farben für die Karten
enum class Farbe {
    HERZ, KARO, PIK, KREUZ
};

// Überladung des << Operators für die Ausgabe von Farben
std::ostream &operator<<(std::ostream &os, Farbe const farbe);

// Definition der Symbole (Werte) der Karten
enum class Symbol {
    Zwei, Drei, Vier, Fuenf, Sechs, Sieben, Acht, Neun, Zehn, Junge, Koenigin, Koenig, Ass
};

// Überladung des << Operators für die Ausgabe von Symbolen
std::ostream &operator<<(std::ostream &os, Symbol const symbol);

// Klassen-Definition für Karte
class Karte {
private:
    Symbol _zahl;
    Farbe _farbe;

public:
    // Konstruktor für die Karte
    Karte(Symbol zahl, Farbe farbe) : _zahl{zahl}, _farbe{farbe} {};

    // Gibt eine textuelle Repräsentation der Karte zurück
    static std::string karteToString(const Karte& karte);

    // Getter für das Symbol (Zahl) der Karte
    Symbol zahl() const { return this->_zahl; }

    // Getter für die Farbe der Karte
    Farbe farbe() const { return this->_farbe; }

    // Berechnet den Wert der Karte basierend auf ihrem Symbol
    int wert() const {
        switch (_zahl) {
            case Symbol::Junge:
            case Symbol::Koenigin:
            case Symbol::Koenig:
                return 10; // König, Königin und Bube sind 10 wert
            case Symbol::Ass:
                return 11; // Ass ist 11 wert
            default:
                return static_cast<int>(_zahl) + 2; // Zwei hat den Index 0, daher +2 ergibt 2 usw.
        }
    }
};

// Überladung des << Operators für die Ausgabe von Karten
std::ostream &operator<<(std::ostream &os, Karte const karte);

// Überladung des < Operators für den Vergleich von Karten
bool operator<(Karte const &lhs, Karte const &rhs);

#endif // KARTE_H
