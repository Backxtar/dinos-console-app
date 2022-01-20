//
// Created by joerg on 17.01.2022.
//

#include "Herbivoren.h"

bool Herbivoren::hide()
{
    if (race == "BRACHIOSAURUS"){

        return (rand() % 100 + 1) <= (calcHideChance() + 1);

    } else if (race == "PARASAUROLOPHUS"){

        return (rand() % 100 + 1) <= (calcHideChance() + 1);

    }
    return false;
}

int Herbivoren::calcHideChance() {

    if (race == "BRACHIOSAURUS") return 50;
    else if (race == "PARASAUROLOPHUS") return 75;

    return 0;
}

void Herbivoren::growingUp() {
   return Dinosaurier::growingUp();
}

bool Herbivoren::breed() {
   return Dinosaurier::breed();
}

int Herbivoren::getWeight() {
   return Dinosaurier::getWeight();
}

int Herbivoren::getMaxWeight() {
   return Dinosaurier::getMaxWeight();
}

bool Herbivoren::die() {
   return Dinosaurier::die();
}