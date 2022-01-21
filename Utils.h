//
// Created by andi on 21.01.2022.
//

#ifndef DINOS_UTILS_H
#define DINOS_UTILS_H

#include <iostream>
#include "Dinosaurier.h"
#include "Herbivoren.h"
#include "Karnivoren.h"

class Utils {

public:
    /* Public static functions */
    static void initPark(std::vector<Karnivoren*> &karVec, std::vector<Herbivoren*> &herVec);

    static void growUp(std::vector<Karnivoren*> &karVec, std::vector<Herbivoren*> &herVec);
    static void hunting(std::vector<Karnivoren*> &karVec, std::vector<Herbivoren*> &herVec);
    static void breed(std::vector<Karnivoren*> &karVec, std::vector<Herbivoren*> &herVec);
};


#endif //DINOS_UTILS_H
