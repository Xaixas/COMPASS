#include "Hangman.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

void Hangman::initialize(std::string start)
{
    chars_guessed = "";
    wrong_guesses = 0;
    remaining = 6;
    strcpy_s(word, start.c_str());
    //strcpy(word, start.c_str());
    word_length = start.length();
    clear_progress(word_length);
}

void Hangman::clear_progress(int length)
{
    for (int i = 0; i < length; i++)
    {
        progress[i] = '-';
    }
    progress[length] = '\0';
}

bool Hangman::check(char user_guess)
{
    bool found = false;
    size_t guessed = chars_guessed.find(user_guess);
    last_guess = user_guess;
    matches = 0;

    unsigned int lastchar = strlen(word) - 1;
    for (int i = 0; i <= lastchar; i++)
    {
        if (user_guess == word[i])
        {
            found = true;
            matches++;
            progress[i] = user_guess;
        }
    }

    if (found)
    {
        if (guessed == std::string::npos)
            chars_guessed += user_guess;
            std::sort(chars_guessed.begin(), chars_guessed.end());
        return found;
    }
    else
    {
        if (guessed == std::string::npos)
        {
            wrong_guesses++;
            remaining--;
            chars_guessed += user_guess;
            std::sort(chars_guessed.begin(), chars_guessed.end());
        }
        return found;
    }
}