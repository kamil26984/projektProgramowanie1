//
// Created by kamil on 27.12.2022.
//

#include "WordSet.h"

void WordSet::wypisz() {
    std::list<Word>::iterator i;
    for(i = getWords().begin(); i != getWords().end(); i++){
        i->wypisz();
    }
}

void pomieszaj(){

}