//
// Created by joerg on 17.01.2022.
//

#ifndef DINOS_HERBIVOREN_H
#define DINOS_HERBIVOREN_H
#include "Dinosaurier.h"

class Herbivoren : public Dinosaurier  {

public:
    Herbivoren() = default;
    const std::string &getArt() const { return art; }

    bool hide();

    //Dinosaur Functions
    void growingUp();
    bool breed();
    int getWeight();
    int getMaxWeight();
    bool die();

private:

    bool isHidden;

    std::string art = "Herbivoren";

    int calcHideChance();

};


#endif //DINOS_HERBIVOREN_H
