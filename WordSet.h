//
// Created by kamil on 27.12.2022.
//

#ifndef PROJEKT_WORDSET_H
#define PROJEKT_WORDSET_H


#include <list>
#include "Word.h"

class WordSet: public Word{
private:
    std::string name;
    std::list<Word> words;

public:
    void setName(std::string name){
        this->name = name;
    }
    void addWord(Word w){
        words.insert(words.end(), w);
    }
    void addSet(std::list<Word> set){
        this->words = set;
    }

    std::string getName(){
        return name;
    }
    std::list<Word> getWords(){
        return words;
    }


public:
    void wypisz();
    void pomieszaj();

};
#endif //PROJEKT_WORDSET_H
