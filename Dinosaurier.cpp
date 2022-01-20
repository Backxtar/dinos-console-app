//
// Created by joerg on 17.01.2022.
//

#include "Dinosaurier.h"
#include <utility>


Dinosaurier::Dinosaurier(int weight_, std::string race_) {
    weight = weight_;
    race = std::move(race_);
    maxWeight = calcMaxWeight();
}

void Dinosaurier::growingUp() {
    if (weight >= maxWeight) return;
    int newWeight = weight + (weight * 100 / calcGrowthRate());
    weight = newWeight;
}

bool Dinosaurier::die() const {
    return (rand() % 100 + 1) <= (calcGrowthRate() + 1);
}

int Dinosaurier::calcMaxWeight() const {
    if (race == "T_REX") return 8000;
    else if (race == "RAPTOR") return 500;
    else if (race == "BRACHIOSAURUS") return 30000;
    else return 1500;
}

int Dinosaurier::calcGrowthRate() const {
    if (race == "T_REX" || race == "BRACHIOSAURUS") return 20;
    else if (race == "RAPTOR") return 30;
    else return 40;
}

bool Dinosaurier::breed() {
    bool vicBreed = false;

    if (rand() % 100 + 1 <= (calcBreedChance() + 1)){
        vicBreed = true;
    }

    return vicBreed;
}

int Dinosaurier::calcBreedChance() const {
    if (race == "T_REX") return 8;
    else if (race == "RAPTOR") return 12;
    else if (race == "BRACHIOSAURUS") return 20;
    else return 85;
}

Dinosaurier::Dinosaurier() {}
