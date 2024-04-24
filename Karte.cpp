#include "Karte.h"


std::ostream &operator<<(std::ostream &os, Farbe const farbe) {
    switch (farbe) {
            case Farbe::HERZ: os << "Herz"; break;
        case Farbe::KARO: os << "Karo"; break;
        case Farbe::PIK: os << "Pik"; break;
        case Farbe::KREUZ: os << "Kreuz"; break;
        default: os << "n/a";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, Symbol const symbol) {
    switch (symbol) {
        case Symbol::Zwei: os << "Zwei"; break;
        case Symbol::Drei: os << "Drei"; break;
        case Symbol::Vier: os << "Vier"; break;
        case Symbol::Fuenf: os << "Fuenf"; break;
        case Symbol::Sechs: os << "Sechs"; break;
        case Symbol::Sieben: os << "Sieben"; break;
        case Symbol::Acht: os << "Acht"; break;
        case Symbol::Neun: os << "Neun"; break;
        case Symbol::Zehn: os << "Zehn"; break;
        case Symbol::Junge: os << "Junge"; break;
        case Symbol::Koenigin: os << "Koenigin"; break;
        case Symbol::Koenig: os << "Koenig"; break;
        case Symbol::Ass: os << "Ass"; break;
        default: os << (int)symbol;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, Karte const karte) {
    os << karte.farbe() << "-" << karte.zahl();
    return os;
}

std::string Karte::karteToString(const Karte& karte) {
    std::string result;
    switch (karte.farbe()) {
        case Farbe::HERZ: result += "Herz"; break;
        case Farbe::KARO: result += "Karo"; break;
        case Farbe::PIK: result += "Pik"; break;
        case Farbe::KREUZ: result += "Kreuz"; break;
        default: result += "n/a";
    }
    result += "-";
    switch (karte.zahl()) {
        case Symbol::Zwei: result += "Zwei"; break;
        case Symbol::Drei: result += "Drei"; break;
        case Symbol::Vier: result += "Vier"; break;
        case Symbol::Fuenf: result += "Fuenf"; break;
        case Symbol::Sechs: result += "Sechs"; break;
        case Symbol::Sieben: result += "Sieben"; break;
        case Symbol::Acht: result += "Acht"; break;
        case Symbol::Neun: result += "Neun"; break;
        case Symbol::Zehn: result += "Zehn"; break;
        case Symbol::Junge: result += "Junge"; break;
        case Symbol::Koenigin: result += "Koenigin"; break;
        case Symbol::Koenig: result += "Koenig"; break;
        case Symbol::Ass: result += "Ass"; break;
        default: result += "n/a";
    }
    return result;
}


bool operator<(Karte const &lhs, Karte const &rhs) {
    if (lhs.farbe() < rhs.farbe()) {
        return true;
    }

    if (lhs.farbe() == rhs.farbe()) {
        return lhs.zahl() < rhs.zahl();
    }

    return false;
}