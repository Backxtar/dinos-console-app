//
// Created by andi on 17.01.2022.
//

#ifndef DINOS_KARNIVOREN_H
#define DINOS_KARNIVOREN_H
#include "Dinosaurier.h"

class Karnivoren : public Dinosaurier {

public:
    /* Constructor */
    Karnivoren(const int &weight_, const std::string &race_) : Dinosaurier(weight_, race_) {
        weight = weight_;
        race = race_;
        maxWeight = calcMaxWeight();
    }

    /* Public functions */
    bool hunt(int karWeight, int herWeight) const;
    bool breed() const override;
    bool die() const override;

    /* Getter & Setter */
    const std::string &getArt() const { return art; }
    int getStomachLevel() const { return stomachLevel; }
    void setStomachLevel(int stomachLevel1) { stomachLevel = stomachLevel1; }
    void reduceStomachLevel(int reduce) { stomachLevel = stomachLevel - reduce; }

private:
    /* Private variables */
    int stomachLevel = 2;
    const std::string art = "KARNIVOR";
};


#endif //DINOS_KARNIVOREN_H
