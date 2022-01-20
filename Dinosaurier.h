//
// Created by joerg on 17.01.2022.
//

#ifndef DINOS_DINOSAURIER_H
#define DINOS_DINOSAURIER_H
#include <iostream>
#include "vector"
#include "Herbivoren.h"
#include "Karnivoren.h"

class Dinosaurier {

public:

    static vector<Herbivoren> herVec;
    static vector<Karnivoren> karVec;

    Dinosaurier(int weight_, std::string race_);

    int getWeight() const { return weight; };
    int getMaxWeight() const { return maxWeight; }

    const std::string &getRace() const { return race; }

    void growingUp();
    bool die() const;

    void breed() ;


protected:
    int weight;
    int maxWeight;
    std::string race;

private:
    int calcMaxWeight() const;
    int calcGrowthRate() const;
    int calcBreedCHance() const;
};


#endif //DINOS_DINOSAURIER_H
