#include "Words.hpp"
#include <fstream>
#include <iostream>
#include <string>

Words::Words(int min, int max)
{
    minlen = min;
    maxlen = max;
    count_candidates();
    load_words();
}

int Words::count_candidates()
{
    std::ifstream list;
    list.open("C:\\Users\\danny\\Documents\\Coding\\COMPASS\\enable1.txt");
    //list.open("enable1.txt");
    if (list.is_open())
    {
        std::string word;
        count = 0;

        while (!list.eof())
        {
            list >> word;
            if (word.length() >= minlen && word.length() <= maxlen)
            {
                count++;
            }
        }
    }
    list.close();

    return count;
}

void Words::load_words()
{
    choices = new std::string[count];

    std::ifstream list;
    list.open("C:\\Users\\danny\\Documents\\Coding\\COMPASS\\enable1.txt");
    //list.open("enable1.txt");
    if (list.is_open())
    {
        std::string word;
        int i = 0;

        while (!list.eof() && i < count)
        {
            list >> word;
            if (word.length() >= minlen && word.length() <= maxlen)
            {
                choices[i] = word;
                i++;
            }
        }
    }
    list.close();
}

std::string Words::pick_word()
{
    if (count == 0)
    {
        return "";
    }
    else
    {
        int random = rand() % count;
        return choices[random];
    }
}

void Words::reset(int min, int max)
{
    minlen = min;
    maxlen = max;
    if (choices != NULL)
        delete[] choices;
    count_candidates();
    load_words();
}