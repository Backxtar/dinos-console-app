//
// Created by joerg on 17.01.2022.
//

#ifndef DINOS_HERBIVOREN_H
#define DINOS_HERBIVOREN_H
#include <utility>

#include "Dinosaurier.h"

class Herbivoren : public Dinosaurier  {

public:
    Herbivoren(int weight_, std::string race_) : Dinosaurier(weight_, race_) {
        weight = weight_;
        race = std::move(race_);
        maxWeight = calcMaxWeight();
    }

    const std::string &getArt() const { return art; }
    bool hide() const;

    //Dinosaur Functions
    bool breed() override;

private:
    const std::string art = "Herbivoren";
    int calcHideChance() const;
    bool isHidden() const;
};


#endif //DINOS_HERBIVOREN_H
