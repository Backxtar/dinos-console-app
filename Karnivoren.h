//
// Created by joerg on 17.01.2022.
//

#ifndef DINOS_KARNIVOREN_H
#define DINOS_KARNIVOREN_H
#include "Dinosaurier.h"

class Karnivoren : public Dinosaurier {

public:
    const std::string &getArt() const { return art; }

    bool hunt();

private:

    int stomachLevel = 2;

    std::string art = "Karnivoren";
};


#endif //DINOS_KARNIVOREN_H
