#include "Hangman.hpp"
#include "HangmanConsole.hpp"
#include "Words.hpp"
#include <ctime>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

int show_menu();
void get_range_num(std::string prompt, int min, int max, int& number);
void play_hangman(Words& words);
void play_hangman(std::string word);

int show_menu()
{
    int choice;

    std::cout << "HANGMAN\n-------\n\n";
    std::cout << "1. VS. computer (random range of length)\n";
    std::cout << "2. VS. computer (words 7 to 12 letters long)\n";
    std::cout << "3  VS. computer (select/change range of length)\n";
    std::cout << "4. VS. computer (use your stored range of length)\n";
    std::cout << "5. VS. player (Player 1 enters word, Player 2 guesses)\n";
    std::cout << "6. Quit\n\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    return choice;
}

void get_range_num(std::string prompt, int min, int max, int& number)
{
    do
    {
        std::cout << prompt;
        std::cin >> number;
    } while (number < min && number > max);
}

void play_hangman(Words& words)
{
    HangmanConsole game(words.pick_word());
    game.run_game();
}

void play_hangman(std::string word)
{
    HangmanConsole game(word);
    game.run_game();
}

int main()
{
    srand(time(0));
    int min3 = 0, max3 = 0;
    bool end = false;

    do
    {
        int max1 = (rand() % 40) + 1;
        int min1 = (rand() % max1) + 1;

        switch (show_menu())
        {
            case 1:
            {
                Words words(min1, max1);
                play_hangman(words);
                break;
            }
            case 2:
            {
                Words words(7, 10);
                play_hangman(words);
                break;
            }
            case 4:
            {
                if (min3 != 0 && max3 != 0)
                {
                    Words words (min3, max3);
                    play_hangman(words);
                    break;
                }
            }
            case 3:
            {
                get_range_num("Enter min: ", 2, 40, min3);
                get_range_num("Enter max: ", min3, 40, max3);
                Words words (min3, max3);
                play_hangman(words);
                break;
            }
            case 5:
            {
                std::string word;
                std::cout << "Player 1 -- Enter your word: ";
                std::cin >> word;
                system("CLS");
                //system("clear");
                play_hangman(word);
                break;
            }
            case 6:
                std::cout << "Quitting...\n";
                end = true;
                break;
        }
    } while (!end);

    return 0;
}