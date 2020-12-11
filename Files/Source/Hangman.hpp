#ifndef HANGMAN_H
#define HANGMAN_H
#include <iostream>
#include <cstring>

class Hangman
{
    private:
        char word[40], progress[40];
        unsigned int word_length;

        void clear_progress(int length);

    protected:
        int matches, wrong_guesses, remaining;
        char last_guess = 0;
        std::string chars_guessed;

        bool check(char user_guess);

    public:
        Hangman(std::string str) { initialize(str); }

        void initialize(std::string start);

        char* get_word() { return word; }
        char* get_progress() { return progress; }
        int get_remaining() { return remaining; }

        bool is_word_complete() { return strcmp(progress, word) == 0; }
};

#endif