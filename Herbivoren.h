//
// Created by joerg on 17.01.2022.
//

#ifndef DINOS_HERBIVOREN_H
#define DINOS_HERBIVOREN_H
#include "Dinosaurier.h"


class Herbivoren : public Dinosaurier  {

public:
    const std::string &getArt() const { return art; }

    bool hide();

private:

    bool isHidden;

    std::string art = "Herbivoren";

    int calcHideChance();

};


#endif //DINOS_HERBIVOREN_H
