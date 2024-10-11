//
// Created by shourya on 11/10/24.
//

#include "Game.h"

#include <iostream>
#include <algorithm>
#include <random>

Game::Game(const std::string& wordPath) {
    std::ifstream file(wordPath);
    if (!file.is_open()) {
        std::cerr << "Could not open file " << wordPath << std::endl;
        exit(1);
    }
    std::string word;
    while (getline(file, word)) {
        words.push_back(word);
    }
    file.close();
}

std::string Game::getWord() {
    // Get random number between 0 and the length of words minus 1
    unsigned long length = words.size();
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(0, length - 1);
    std::string word = words[dist(rng)];
    return word;
}


bool Game::isValidWord(const std::string& word) {
    const bool result = std::ranges::binary_search(words, word);
    return result;
}

std::string Game::getInput() {
    std::string guess;
    std::getline(std::cin, guess);
    return guess;
}

bool Game::hasWon() const {
    // Check if board is equal to the word
    for (int i = 0; i < word.size(); i++) {
        if (word[i] != board[i])
            return false;
    }
    return true;
}

bool Game::promptReplay() {
    std::string input;
    while (true) {
        std::cout << "Do you want to play again? (Y/N) \n";
        input = getInput();
        if (input == "N") return false;
        if (input == "Y") return true;
        std::cout << "Invalid input. ";
    }
}

void Game::Loop() {
    while (isRunning) {
        // Make word
        word = getWord();

        std::ranges::transform(word, word.begin(), ::tolower);

        board = {};
        guesses = {};
        guessesLeft = 11;

        // Update board
        for (const auto letter : word) {
            board.push_back('_');
        }
        while (true) {
            if (guessesLeft == 0) {
                std::cout << "YOU LOSE!!\n";
                if (!promptReplay()) {
                    isRunning = false;
                    break;
                }
                break;
            }

            std::cout << "Input guess: ";
            std::string guess = getInput();
            std::cout << "\n";


            std::ranges::transform(guess, guess.begin(), ::tolower);

            if (guess.length() > 1 && isValidWord(guess) == false) {
                std::cout << "That's not a valid word!" << "\n";
                continue;
            }

            // Get matching letters
            for (int x = 0; x < guess.size(); x++) {
                if (std::count(board.begin(), board.end(), guess[x]) > 0) {
                    continue;
                }

                if (std::count(guesses.begin(), guesses.end(), guess[x]) == 0) {
                    guesses.push_back(guess[x]);
                }

                if (word.find_first_of(guess[x]) != std::string::npos) {
                    for (int j = 0; j < board.size(); j++) {
                        if (word[j] == guess[x]) {
                            board[j] = word[j];
                        }
                    }
                } else {
                    guessesLeft -= 1;
                }
            }

            // Check if word is correct
            if (hasWon()) {
                std::cout << "YOU WON!!\n";
                if (!promptReplay()) {
                    isRunning = false;
                    break;
                }
                break;
            }



            OutputBoard();

        }


    }
}

void Game::OutputBoard() {
    std::cout << "\nLetters: ";
    for (const auto letter : board) {
        std::cout << letter;
    }
    std::cout << "\n";
    std::cout << "Guesses: ";
    for (const auto guess : guesses) {
        std::cout << guess << ", ";
    }
    std::cout << "\n\n";

    std::cout << "You have " << guessesLeft << " guesses left!!\n";
}
