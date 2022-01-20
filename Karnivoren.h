//
// Created by joerg on 17.01.2022.
//

#ifndef DINOS_KARNIVOREN_H
#define DINOS_KARNIVOREN_H
#include "Dinosaurier.h"

class Karnivoren : public Dinosaurier {

public:
    Karnivoren() = default;
    
    const std::string &getArt() const { return art; }

    bool hunt(int kar, int herb);

    //Getter/Setter
    int getStomachLevel() const {return stomachLevel;}
    int setStomachLevel(int stomachLevel1) {this -> stomachLevel = stomachLevel1;}
    int reduceStomachLevel(int reduce) {this -> stomachLevel = stomachLevel - reduce;}

    //Dinosaurier Functions
    void growingUp();
    bool breed();
    int getWeight();
    int getMaxWeight();
    bool die();

private:

    int stomachLevel = 2;
    std::string art = "Karnivoren";
};


#endif //DINOS_KARNIVOREN_H
