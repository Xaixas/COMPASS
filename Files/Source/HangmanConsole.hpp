#ifndef HANGMANCONSOLE_H
#define HANGMANCONSOLE_H
#include <iostream>
#include "Hangman.hpp"

class HangmanConsole : public Hangman
{
    public:
        HangmanConsole(std::string start)
            : Hangman(start) {}

        void show_status(int stage);
        void show_info();
        void run_game();

        friend std::istream& operator>>(std::istream& in, HangmanConsole& hangman);
};

#endif