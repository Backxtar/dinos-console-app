//
// Created by andi on 21.01.2022.
//

#ifndef DINOS_MAIN_H
#define DINOS_MAIN_H

#include <iostream>
#include <utility>
#include "Dinosaurier.h"
#include "Herbivoren.h"
#include "Karnivoren.h"
#include "vector"
#include "Utils.h"

/* Global vectors */
std::vector<Herbivoren*> herVec;
std::vector<Karnivoren*> karVec;

/* functions */
void passingTime();

#endif //DINOS_MAIN_H
