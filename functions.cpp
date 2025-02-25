#include "functions.hpp"

string pickWord() {
    srand(time(0));
    int count = 0;
    int random = rand() % 5757;

    ifstream helper("5_letter_words.txt");
    if (!helper) {
        return "Failed, try again";
    }
    string word;

    while(helper >> word) {
        if (count == random) {
            return word;
        }
        count++;
    }
    return word;
}

bool guess_correct();

bool complete();

char GetNextGuess(const vector <char> already_guessed);

bool checkEndConditions();
