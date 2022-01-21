//
// Created by andi on 17.01.2022.
//

#include "Karnivoren.h"

bool Karnivoren::hunt(int karWeight, int herWeight) const
{
    bool hunted;

    if (karWeight > herWeight) hunted = true;
    else hunted = false;

    if (hunted) std::cout << "(" << getArt() << ") -> " << getRace() << " hat erfolgreich gejagt!" << std::endl;
    return hunted;
}

bool Karnivoren::breed() const {
    bool breed = rand() % 100 + 1 <= (calcBreedChance() + 1);
    if (breed) std::cout << "Ein " << "(" << getArt() << ") -> " << getRace() << " wurde geboren!" << std::endl;
    return breed;
}

bool Karnivoren::die() const {
    bool died;
    died = (rand() % 100 + 1) <= (calcGrowthRate() + 1);
    if (died) std::cout << "Ein " << "(" << getArt() << ") -> " << getRace() << " ist an Altersschwaeche gestorben!" << std::endl;
    return died;
}

