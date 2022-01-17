//
// Created by joerg on 17.01.2022.
//

#ifndef DINOS_DINOSAURIER_H
#define DINOS_DINOSAURIER_H
#include <iostream>

class Dinosaurier {

public:
    Dinosaurier(int weight_, std::string race_);

    int getWeight() const { return weight; };
    int getMaxWeight() const { return maxWeight; }
    const std::string &getRace() const { return race; }

    void growingUp();
    bool die() const;
    virtual void breed() = 0;

protected:
    int weight;
    int maxWeight;
    std::string race;

private:
    int calcMaxWeight() const;
    int calcGrowthRate() const;
};


#endif //DINOS_DINOSAURIER_H
