//
// Created by kamil on 27.12.2022.
//
#ifndef PROJEKT_WORD_H
#define PROJEKT_WORD_H


#include <string>

class Word {
private:
    std::string word, translation;
public:
    Word(std::string word, std::string translation){
        this->word = word;
        this->translation = translation;
    }
    Word(){
        this->word = "";
        this->translation = "";
    }
    void setWord(std::string word){
        this->word = word;
    }
    void setTranslation(std::string translation){
        this->translation = translation;
    }

    std::string getWord(){
        return this->word;
    }
    std::string getTranslation(){
        return this->translation;
    }

    public:
    void wypisz();
};


#endif //PROJEKT_WORD_H
