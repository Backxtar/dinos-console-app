//
// Created by joerg on 21.01.2022.
//

#include "Utils.h"

void Utils::initPark(std::vector<Karnivoren *> &karVec, std::vector<Herbivoren *> &herVec)
{
    for (int i = 0; i < 4; i++)
    {
        auto *her = new Herbivoren(30000, "BRACHIOSAURUS");
        herVec.push_back(her);
        auto *kar = new Karnivoren(500, "RAPTOR");
        karVec.push_back(kar);
    }

    for (int i = 0; i < 2; i++)
    {
        auto *kar = new Karnivoren(8000, "T_REX");
        karVec.push_back(kar);
    }

    for (int i = 0; i < 5; i++)
    {
        auto *her = new Herbivoren(1500, "PARASAUROLOPHUS");
        herVec.push_back(her);
    }
}

void Utils::growUp(std::vector<Karnivoren *> &karVec, std::vector<Herbivoren *> &herVec)
{
    for (int her = 0; her < herVec.size(); her++)
    {
        herVec.at(her)->growingUp();
        if (herVec.at(her)->getWeight() == herVec.at(her)->getMaxWeight() && herVec.at(her)->die())
            herVec.erase(herVec.begin() + her); // Delete HERBIVOR
    }

    for (int kar = 0; kar < karVec.size(); kar++)
    {
        karVec.at(kar)->growingUp();
        if (karVec.at(kar)->getWeight() == karVec.at(kar)->getMaxWeight() && karVec.at(kar)->die())
            karVec.erase(karVec.begin() + kar); // DELETE KARNIVOR
    }
}

void Utils::hunting(std::vector<Karnivoren *> &karVec, std::vector<Herbivoren *> &herVec)
{
    for (int kar = 0; kar < karVec.size(); kar++)
    {
        for (int her = 0; her < herVec.size(); her++)
        {
            if (karVec.at(kar)->hunt(karVec.at(kar)->getWeight(), herVec.at(her)->getWeight())
            && karVec.at(kar)->getStomachLevel() != 2 &&!herVec.at(her)->hide())
            {
                herVec.at(her)->eaten();                                                 // HERBIVOR was eaten
                karVec.at(kar)->setStomachLevel(2);                          // KARNIVOR has eaten
                herVec.erase(herVec.begin() + her);                                      // Delete HERBIVOR
            }
            else karVec.at(kar)->reduceStomachLevel(1);                           // Nothing to eat for KARNIVOR
        }
        if (karVec.at(kar)->getStomachLevel() <= 0) karVec.erase(karVec.begin() + kar); // KARNIVOR dies if stomach gets zero
    }
}

void Utils::breed(std::vector<Karnivoren *> &karVec, std::vector<Herbivoren *> &herVec)
{
    for (auto &vecK: karVec)
    {
        if (vecK->breed()) // Create new dino
        {
            int weight = vecK->getWeight() / 100 * 20;
            const std::string &race = vecK->getRace();
            auto *kar = new Karnivoren(weight, race);
            karVec.push_back(kar);
        }
    }
    for (auto &vecH: herVec)
    {
        if (vecH->breed()) // Create new dino
        {
            int weight = vecH->getWeight() / 100 * 20;
            const std::string &race = vecH->getRace();
            auto *her = new Herbivoren(weight, race);
            herVec.push_back(her);
        }
    }
}
