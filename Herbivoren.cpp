//
// Created by joerg on 17.01.2022.
//

#include "Herbivoren.h"

bool Herbivoren::hide() const
{
    bool hidden;
    if (race == "BRACHIOSAURUS" || race == "PARASAUROLOPHUS") hidden = isHidden();
    else hidden = false;

    if (hidden) std::cout << "(" << getArt() << ") -> " << getRace() << " hat sich erfolgreich versteck!" << std::endl;
    return hidden;
}

int Herbivoren::calcHideChance() const {
    if (race == "BRACHIOSAURUS") return 50;
    else if (race == "PARASAUROLOPHUS") return 75;
    else return 0;
}

bool Herbivoren::breed() {
    bool breed = rand() % 100 + 1 <= (calcBreedChance() + 1);
    if (breed) std::cout << "Ein " << "(" << getArt() << ") -> " << getRace() << " wurde geboren!" << std::endl;
    return breed;
}

bool Herbivoren::isHidden() const {
    return (rand() % 100 + 1) <= (calcHideChance() + 1);
}
