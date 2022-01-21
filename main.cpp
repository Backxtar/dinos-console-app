#include <iostream>
#include "Dinosaurier.h"
#include "Herbivoren.h"
#include "Karnivoren.h"
#include "vector"
#include "Utils.h"

/* Global vectors */
std::vector<Herbivoren*> herVec;
std::vector<Karnivoren*> karVec;

/* Register functions */
void passingTime();

/* Start program */
int main()
{
    int timePasses;

    while (true)
    {
        std::cout << "Bitte geben sie die Anzahl an Monaten an, die simuliert werden sollen: ";
        std::cin >> timePasses;
        if(timePasses > 0) break;
    }
    Utils::initPark(karVec, herVec);

    for (int i = 0; i < timePasses; i++)
        passingTime();
}

void passingTime()
{
    Utils::growUp(karVec, herVec); //Growing Steps + Die at an old age
    Utils::hunting(karVec, herVec); //Simulating the hunts + Stomach-Level reduce
    Utils::breed(karVec, herVec); //Breed
    std::cout   << "========================" << std::endl
                << "HERBIVOREN: " << herVec.size() << std::endl
                << "KARNIVOREN: " << karVec.size() << std::endl
                << "========================" << std::endl;
}
