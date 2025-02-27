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

bool GuessValid(char guess, vector<char> guessed_letters) {
    for (int i = 0; i < guessed_letters.size(); i++) {
      if (guessed_letters[i] == guess) {
        return false;
      }
    }
    return true;
  }
  
 
  string GetBlankWord(unsigned int size) {
    string helper;
  
    for (unsigned int i = 0; i < size; i++) {
      helper.push_back('-');
    }
  
    return helper;
  }
  

  bool WordCompleted(const string& word) {
    for (long i = 0; i < word.size(); i++) {
      if (word[i] == '-') {
        return false;
      }
    }
    return true;
  }
  
  
  void PrintState(const string& mystery_word_so_far, unsigned int misses) {
    cout << endl;
    cout << "--- Current State --- " << endl;
  
    cout << "You have " << 6 - misses << " lives left." << endl;
    cout << "Word: ";
    for (unsigned int i = 0; i < mystery_word_so_far.length(); i++) {
      cout << mystery_word_so_far[i] << " ";
    }
    cout << endl;
    cout << endl;
  }
  
  
  
 
  char GetNextGuess(const vector<char>& guessed_letters) {
    cout << "What is your next guess? ";
    char x;
  
    while (!(cin >> x) || !GuessValid(x, guessed_letters) || !isalpha(x) ||
           isupper(x)) {
      cout << endl;
      cout << "Invalid guess. Please enter a lowercase letter that you have "
           << "not guessed yet : ";
    }
  
    return x;
  }
  

  bool CheckWordForGuess(string& word_so_far, string word, char guess) {
    bool helper = false;
    for (long i = 0; i < word.size(); i++) {
      if (word[i] == guess) {
        word_so_far[i] = guess;
        helper = true;
      }
    }
    return helper;
  }
  
  
  void GuessFeedback(bool correct_guess, char guess) {
    cout << endl;
    if (correct_guess) {
      cout << "The letter \'" << guess << "\' is in the word!" << endl;
    } else {
      cout << "The letter \'" << guess << "\' is not in the word." << endl;
    }
  }
  
  
  bool CheckEndConditions(const string& word_so_far,
                          unsigned int misses,
                          const string& solution) {
    bool helper = WordCompleted(word_so_far);
    if (helper) {
      PrintState(word_so_far, misses);
      cout << "You win! You guessed the word, " << word_so_far << "." << endl;
      return true;
    }
  
    if (misses == 6) {
      PrintState(word_so_far, misses);
      cout << "You used up your last guess and lost!" << endl;
      cout << "The word was, " << solution << "." << endl;
      return true;
    }
  
    return false;
  }