#include "HangmanConsole.hpp"
#include "Hangman.hpp"
#include <iostream>

void HangmanConsole::show_status(int stage)
{
    switch (stage)
    {
    case 0:
        std::cout << " +-----\n";
        std::cout << " |     \n";
        std::cout << " |     \n";
        std::cout << " |     \n";
        std::cout << " |     \n";
        std::cout << " ----- \n";
        break;
    case 1:
        std::cout << " +-----\n";
        std::cout << " |  O  \n";
        std::cout << " |      \n";
        std::cout << " |      \n";
        std::cout << " |      \n";
        std::cout << " ----- \n";
        break;
    case 2:
        std::cout << " +-----\n";
        std::cout << " |  O  \n";
        std::cout << " |  |   \n";
        std::cout << " |  |   \n";
        std::cout << " |      \n";
        std::cout << " ----- \n";
        break;
    case 3:
        std::cout << " +-----\n";
        std::cout << " |  O  \n";
        std::cout << " | /|   \n";
        std::cout << " |  |   \n";
        std::cout << " |      \n";
        std::cout << " ----- \n";
        break;
    case 4:
        std::cout << " +-----\n";
        std::cout << " |  O  \n";
        std::cout << " | /|\\ \n";
        std::cout << " |  |   \n";
        std::cout << " |      \n";
        std::cout << " ----- \n";
        break;
    case 5:
        std::cout << " +-----\n";
        std::cout << " |  O  \n";
        std::cout << " | /|\\ \n";
        std::cout << " |  |   \n";
        std::cout << " | /    \n";
        std::cout << " ----- \n";
        break;
    case 6:
        std::cout << " +-----\n";
        std::cout << " |  O  \n";
        std::cout << " | /|\\ \n";
        std::cout << " |  |   \n";
        std::cout << " | / \\ \n";
        std::cout << " ----- \n";
        break;
    }
}

void HangmanConsole::show_info()
{
    show_status(wrong_guesses);
    std::cout << std::endl << get_progress() << std::endl;
    if (matches == 1)
        std::cout << matches << " match found for '" << last_guess << "'\n";
    else
        std::cout << matches << " matches found for '" << last_guess << "'\n";
    std::cout << "Letters guessed: " << chars_guessed << std::endl;
    std::cout << "Wrong guesses made: " << wrong_guesses << std::endl;

    if (remaining > 0 && !is_word_complete())
        std::cout << "Attempts remaining: " << remaining << std::endl;
    else if (remaining > 0 && is_word_complete())
        std::cout << "\nYou guessed it! The word was " << get_word() << "\n\n";
    else
        std::cout << "\nNo attempts left! The word was " << get_word() << "\nGame Over\n\n";
}

void HangmanConsole::run_game()
{
    std::cout << "Your word is: " << this->get_progress() << std::endl;

    while (!this->is_word_complete() && this->get_remaining() > 0)
    {
        std::cout << std::endl;
        std::cin >> *this;

        system("CLS");
        //system("clear");
        this->show_info();
    }
}

std::istream& operator>>(std::istream& in, HangmanConsole& hangman)
{
    char guess;
    do
    {
        std::cout << "Enter your guess: ";
        in >> guess;
    } while (false);
    hangman.check(guess);
    
    return in;
}