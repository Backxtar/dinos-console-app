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
    for (int i = 0; i < herVec.size(); i++)
    {
        herVec.at(i)->growingUp();
        if (herVec.at(i)->getWeight() == herVec.at(i)->getMaxWeight() && herVec.at(i)->die())
            herVec.erase(herVec.begin() + i); //löschen
    }

    for (int i = 0; i < karVec.size(); i++)
    {
        karVec.at(i)->growingUp();
        if (karVec.at(i)->getWeight() == karVec.at(i)->getMaxWeight() && karVec.at(i)->die())
            karVec.erase(karVec.begin() + i); //löschen
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
                herVec.at(her)->eaten(); //Wurde gefressen!
                karVec.at(kar)->setStomachLevel(2); //Auffüllen der hunger variable
                herVec.erase(herVec.begin() + her); //Löschen des Opfers
            }
            else karVec.at(kar)->reduceStomachLevel(1); //Wenn kein Fressen gefunden, reduzier stomach
        }
        if (karVec.at(kar)->getStomachLevel() <= 0) karVec.erase(karVec.begin() + kar); //Wenn stomach <= 0 -> tot
    }
}

void Utils::breed(std::vector<Karnivoren *> &karVec, std::vector<Herbivoren *> &herVec)
{
    for (auto &vecK: karVec)
    {
        if (vecK->breed())
        {
            //neuen dino erstellen
            int weight = vecK->getWeight() / 100 * 20;
            std::string race = vecK->getRace();
            auto *kar = new Karnivoren(weight, race);
            karVec.push_back(kar);
        }
    }
    for (auto &vecH: herVec)
    {
        if (vecH->breed())
        {
            //neuen dino erstellen
            int weight = vecH->getWeight() / 100 * 20;
            std::string race = vecH->getRace();
            auto *her = new Herbivoren(weight, race);
            herVec.push_back(her);
        }
    }
}
