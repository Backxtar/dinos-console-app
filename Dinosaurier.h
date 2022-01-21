//
// Created by andi on 17.01.2022.
//

#ifndef DINOS_DINOSAURIER_H
#define DINOS_DINOSAURIER_H
#include <iostream>
#include "vector"


class Dinosaurier {

public:
    /* Constructor */
    Dinosaurier(const int &weight_, const std::string& race_);

    /* Public functions */
    virtual void growingUp();
    virtual bool die() const = 0;
    virtual bool breed() const = 0;

    /* Getter & Setter */
    virtual int getWeight() const { return weight; };
    virtual int getMaxWeight() const { return maxWeight; }
    const std::string &getRace() const { return race; }

protected:
    /* Protected variables */
    int weight {};      // Empty initialize -> Set with sub-constructor
    int maxWeight {};   // Empty initialize -> Set with sub-constructor
    std::string race;

    /* Protected functions */
    int calcMaxWeight() const;
    int calcBreedChance() const;
    int calcGrowthRate() const;
};


#endif //DINOS_DINOSAURIER_H
