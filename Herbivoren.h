//
// Created by andi on 17.01.2022.
//

#ifndef DINOS_HERBIVOREN_H
#define DINOS_HERBIVOREN_H
#include <utility>
#include "Dinosaurier.h"

class Herbivoren : public Dinosaurier  {

public:
    /* Constructor */
    Herbivoren(const int &weight_, const std::string &race_) : Dinosaurier(weight_, race_) {
        weight = weight_;
        race = race_;
        maxWeight = calcMaxWeight();
    }

    /* Public functions */
    bool hide() const;
    bool breed() const override;
    bool die() const override;
    void eaten() const;

    /* Getter & Setter */
    const std::string &getArt() const { return art; }

private:
    /* Private variables */
    const std::string art = "HERBIVOR";

    /* Private functions */
    int calcHideChance() const;
    bool isHidden() const;
};


#endif //DINOS_HERBIVOREN_H
