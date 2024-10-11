//
// Created by Shourya on 11/10/24.
//

#pragma once

#include <string>
#include <fstream>
#include <vector>

class Game {
private:
    std::string word;
    std::string guess;
    std::vector<std::string> words;
    std::vector<char> board = {};
    std::vector<char> guesses = {};
    int guessesLeft = 11;

    bool isRunning = true;

public:
    explicit Game(const std::string& wordPath);

    std::string getWord();
    bool isValidWord(const std::string& word);
    static std::string getInput();
    bool hasWon() const;

    bool promptReplay();

    void Loop();
    void OutputBoard();
};
