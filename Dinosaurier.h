//
// Created by joerg on 17.01.2022.
//

#ifndef DINOS_DINOSAURIER_H
#define DINOS_DINOSAURIER_H
#include <iostream>
#include "vector"


class Dinosaurier {

public:
    Dinosaurier(const int &weight_, const std::string& race_);

    virtual int getWeight() { return weight; };
    virtual int getMaxWeight() { return maxWeight; }
    const std::string &getRace() const { return race; }
    virtual void growingUp();
    virtual bool die();
    virtual bool breed() = 0;


protected:
    int weight{};
    int maxWeight{};
    std::string race;

    int calcMaxWeight() const;
    int calcBreedChance() const;

private:
    int calcGrowthRate() const;
};


#endif //DINOS_DINOSAURIER_H
