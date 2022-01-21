//
// Created by andi on 17.01.2022.
//

#include "Dinosaurier.h"


Dinosaurier::Dinosaurier(const int &weight_, const std::string &race_) {
    // Empty constructor -> Send variables to sub-constructors
}

void Dinosaurier::growingUp() {
    if (weight >= maxWeight) return;
    int newWeight = weight + (weight * 100 / calcGrowthRate());
    weight = newWeight;
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

int Dinosaurier::calcBreedChance() const {
    if (race == "T_REX") return 8;
    else if (race == "RAPTOR") return 12;
    else if (race == "BRACHIOSAURUS") return 20;
    else return 85;
}
