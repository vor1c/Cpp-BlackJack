#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include "Karte.h"
#include "Deck.h"
#include "Hand.h"
#include "UserManager.h"

// Funktion zur Berechnung der Punktzahl einer Hand
int punktzahlBerechnen(const Hand& hand) {
    int summe = 0;
    int asse = 0;
    for (const auto& karte : hand) {
        int wert = karte.wert();
        if (wert == 11) {
            asse++;
            summe += 11;
        } else {
            summe += wert;
        }
    }
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

void dealerSpielt(Hand& dealerHand, Deck& deck) {
    while (punktzahlBerechnen(dealerHand) < 17) {
        dealerHand.hinzufuegen(deck.nehmen());
    }
}

std::string punktzahlZuString(int punkte) {
    if (punkte > 21) {
        return " (Über 21)";
    } else {
        return " (Punktzahl: " + std::to_string(punkte) + ")";
    }
}

int main() {
    std::vector<User> users;
    if (!loadUsers("points.voric", users)) {
        std::cerr << "Fehler beim Laden der Benutzerdaten. Programm wird beendet.\n";
        return 1;
    }

    User* currentUser = nullptr;
    while (!currentUser) {
        std::cout << "1. Anmelden\n2. Registrieren\nWähle eine Option: ";
        int option;
        std::cin >> option;

        if (option == 1) {
            currentUser = authenticateUser(users);
        } else if (option == 2) {
            currentUser = registerUser(users);
        } else {
            std::cout << "Ungültige Eingabe, bitte erneut versuchen.\n";
        }

        if (!currentUser) {
            std::cout << "Anmeldung fehlgeschlagen, bitte erneut versuchen.\n";
        }
    }

    std::cout << "Willkommen " << currentUser->username << "!\n";

    while (true) {
        int bet = getBetAmount(*currentUser);
        Franzoesisch deck;
        deck.mischen();
        Hand spielerHand, dealerHand;
        spielerHand.hinzufuegen(deck.nehmen());
        dealerHand.hinzufuegen(deck.nehmen());
        spielerHand.hinzufuegen(deck.nehmen());
        dealerHand.hinzufuegen(deck.nehmen());

        std::cout << "Deine Hand: " << handToString(spielerHand, true) << punktzahlZuString(punktzahlBerechnen(spielerHand)) << std::endl;
        std::cout << "Dealer zeigt: " << handToString(dealerHand, false) << std::endl;

        char choice;
        while (true) {
            std::cout << "Möchtest du eine weitere Karte ziehen? (j/n): ";
            std::cin >> choice;
            if (choice == 'j') {
                spielerHand.hinzufuegen(deck.nehmen());
                std::cout << "Deine Hand: " << handToString(spielerHand, true) << punktzahlZuString(punktzahlBerechnen(spielerHand)) << std::endl;
                if (punktzahlBerechnen(spielerHand) > 21) {
                    std::cout << "Überzogen! Du hast verloren.\n";
                    currentUser->cash -= bet;
                    break;
                }
            } else {
                break;
            }
        }

        if (punktzahlBerechnen(spielerHand) <= 21) {
            dealerSpielt(dealerHand, deck);
            std::cout << "Dealer's Hand: " << handToString(dealerHand, true) << punktzahlZuString(punktzahlBerechnen(dealerHand)) << std::endl;
        }

        int spielerPunkte = punktzahlBerechnen(spielerHand);
        int dealerPunkte = punktzahlBerechnen(dealerHand);
        if (dealerPunkte > 21 || spielerPunkte > dealerPunkte) {
            std::cout << "Glückwunsch! Du hast gewonnen!\n";
            currentUser->cash += bet * 2;
        } else if (dealerPunkte > spielerPunkte) {
            std::cout << "Dealer gewinnt!\n";
            currentUser->cash -= bet;
        } else {
            std::cout << "Unentschieden!\n";
        }

        saveUsers("points.voric", users);

        std::cout << "Möchtest du eine weitere Runde spielen? (j/n): ";
        std::cin >> choice;
        if (choice != 'j') break; // Verlässt die Spielschleife, wenn der Benutzer keine weitere Runde spielen möchte
    }

    std::cout << "Abmeldung. Danke fürs Spielen!\n";
    return 0;
}
