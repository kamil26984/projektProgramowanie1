//
// Created by kamil on 27.12.2022.
//

#include <iostream>
#include "Word.h"

void Word::wypisz() {
    std::cout << getWord() << " " << getTranslation() << std::endl;
}

