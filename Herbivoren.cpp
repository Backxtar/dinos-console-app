//
// Created by andi on 17.01.2022.
//

#include "Herbivoren.h"

bool Herbivoren::hide() const
{
    bool hidden = (race == "BRACHIOSAURUS" || race == "PARASAUROLOPHUS") && isHidden();
    if (hidden) std::cout << "(" << getArt() << ") -> " << getRace() << " hat sich erfolgreich versteck!" << std::endl;
    return hidden;
}

int Herbivoren::calcHideChance() const {
    int hideChance;
    if (race == "BRACHIOSAURUS") hideChance = 50;
    else if (race == "PARASAUROLOPHUS") hideChance = 75;
    else hideChance = 0;
    return hideChance;
}

bool Herbivoren::breed() const {
    bool breed = rand() % 100 + 1 <= (calcBreedChance() + 1);
    if (breed) std::cout << "Ein " << "(" << getArt() << ") -> " << getRace() << " wurde geboren!" << std::endl;
    return breed;
}

bool Herbivoren::isHidden() const {
    return (rand() % 100 + 1) <= (calcHideChance() + 1);
}

bool Herbivoren::die() const {
    bool died;
    died = (rand() % 100 + 1) <= (calcGrowthRate() + 1);
    if (died) std::cout << "Ein " << "(" << getArt() << ") -> " << getRace() << " ist an Altersschwaeche gestorben!" << std::endl;
    return died;
}

void Herbivoren::eaten() const {
    std::cout << "Ein " << "(" << getArt() << ") -> " << getRace() << " wurde von einem KARNIVOR gefressen!" << std::endl;
}
