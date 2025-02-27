#define CROW_MAIN
#include "crow.h"
#include "functions.hpp"
#include <vector>
using namespace std;

string word;
string display;
int misses = 0;
vector<char> guesses;

crow::response startGame() {
    crow::json::wvalue jelly;
    jelly["word"] = display;
    jelly["remaining"] = 6 - misses;
    return jelly;
}


void start() {
    word = PickWord();
    string x;
    for (int i  = 0; i < word.size(); i++) {
        x += "-";
    }
    guesses.clear();

}




int main() {
    crow::SimpleApp app;
    CROW_ROUTE(app, "/start").methods("GET"_method)([] {
        start();
        return startGame();
    });
    app.port(8080).multithreaded().run();
}






