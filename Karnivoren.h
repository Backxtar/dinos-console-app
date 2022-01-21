//
// Created by joerg on 17.01.2022.
//

#ifndef DINOS_KARNIVOREN_H
#define DINOS_KARNIVOREN_H
#include "Dinosaurier.h"

class Karnivoren : public Dinosaurier {

public:
    Karnivoren(int weight_, std::string race_) : Dinosaurier(weight_, race_) {
        weight = weight_;
        race = std::move(race_);
        maxWeight = calcMaxWeight();
    }
    
    const std::string &getArt() const { return art; }
    bool hunt(int karWeight, int herWeight) const;

    //Getter/Setter
    int getStomachLevel() const { return stomachLevel; }
    void setStomachLevel(int stomachLevel1) { stomachLevel = stomachLevel1; }
    void reduceStomachLevel(int reduce) { stomachLevel = stomachLevel - reduce; }

    //Dinosaurier Functions
    bool breed() override;

private:
    int stomachLevel = 2;
    const std::string art = "Karnivoren";
};


#endif //DINOS_KARNIVOREN_H
