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
}

int Herbivoren::calcHideChance() {

    if (race == "BRACHIOSAURUS") return 50;
    else if (race == "PARASAUROLOPHUS") return 75;

}
