#include "main.h"

/* Start program */
int main()
{
    int timePasses;

    while (true)
    {
        std::cout << "Bitte geben sie die Anzahl an Monaten an, die simuliert werden sollen: " << std::endl;
        std::cin >> timePasses;
        if(timePasses > 0)
        {
            std::cout << "==========START==========" << std::endl;
            break;
        }
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
    std::cout   << "=========================" << std::endl
                << "HERBIVOREN: " << herVec.size() << std::endl
                << "KARNIVOREN: " << karVec.size() << std::endl
                << "=========================" << std::endl;
}
