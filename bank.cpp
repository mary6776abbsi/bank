#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isValidCardPrefix(const string& cardNumber) {
    unordered_map<string, string> validPrefixes = {
        {"603799", "MELI"},
        {"589210", "SEPAH"},
        {"627353", "TEJARAT"},
        {"589463", "REFH"},
        {"627381", "EN"},
        {"621986", "SAMAN"},
        {"639346", "PASARGAD"},
        {"627412", "EGHTESAD NOVIN"},
        {"622106", "PARSIAN"},
        {"639607", "SARMAYE"}
        // Add other prefixes here as needed
    };

    string prefix = cardNumber.substr(0, 6);
    return validPrefixes.find(prefix) != validPrefixes.end();
}

void displayCardNumber(const int cardNumber[], int length) {
    for (int i = 0; i < length; i++) {
        if (i > 0 && i % 4 == 0) {
            cout << "-";
        }
        cout << cardNumber[i];
    }
    cout << endl;
}

int main() {
    const int cardLength = 16;
    int cardNumber[cardLength];
    int currentIndex = 0;
    string input;

    cout << "Please enter your 16-digit card number, one digit at a time:" << endl;

    while (currentIndex < cardLength) {
        cout << "Enter digit " << (currentIndex + 1) << ": ";
        cin >> input;

        if (input.length() != 1 || !isdigit(input[0])) {
            cout << "Invalid input. Please enter a single digit (0-9)." << endl;
            continue;
        }

        cardNumber[currentIndex] = input[0] - '0';
        currentIndex++;

        cout << "Current card number: ";
        displayCardNumber(cardNumber, currentIndex);

        // Validate card prefix after first 6 digits
        if (currentIndex == 6) {
            string cardPrefix = "";
            for (int i = 0; i < 6; i++) {
                cardPrefix += to_string(cardNumber[i]);
            }

            if (!isValidCardPrefix(cardPrefix)) {
                cout << "Invalid card prefix. Please check your card." << endl;
                return 1;
            }
            else {
                cout << "Card prefix is valid." << endl;
            }
        }
    }

    cout << "Final card number: ";
    displayCardNumber(cardNumber, cardLength);

    return 0;
}
