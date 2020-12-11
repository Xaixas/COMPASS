#ifndef WORDS_H
#define WORDS_H
#include <iostream>

class Words
{
    private:
        unsigned int minlen, maxlen;
        int count;
        std::string* choices;

        int count_candidates();
        void load_words();

    public:
        Words(int min, int max);

        std::string pick_word();

        void reset(int min, int max);

        ~Words() { delete[] choices; }
};

#endif