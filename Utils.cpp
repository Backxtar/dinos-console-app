//
// Created by joerg on 21.01.2022.
//

#include "Utils.h"

void Utils::initPark(std::vector<Karnivoren*> &karVec, std::vector<Herbivoren*> &herVec)
{
    for (int i = 0; i < 4; i++) {
        auto* her = new Herbivoren(30000, "BRACHIOSAURUS");
        herVec.push_back(her);
        auto* kar = new Karnivoren(500, "RAPTOR");
        karVec.push_back(kar);
    }

    for (int i = 0; i < 2; i++) {
        auto* kar = new Karnivoren(8000, "T_REX");
        karVec.push_back(kar);
    }

    for (int i = 0; i < 5; i++) {
        auto* her = new Herbivoren(1500, "PARASAUROLOPHUS");
        herVec.push_back(her);
    }
}

void Utils::growUp(std::vector<Karnivoren*> &karVec, std::vector<Herbivoren*> &herVec)
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
        {
            karVec.erase(karVec.begin() + i); //löschen
        }
    }
}

void Utils::hunting(std::vector<Karnivoren*> &karVec, std::vector<Herbivoren*> &herVec)
{
    for (int vecK = 0; vecK < karVec.size() ; vecK++) {
        for (int vecH = 0; vecH < herVec.size() ; vecH++) {
            if (karVec.at(vecK)->hunt(karVec.at(vecK)->getWeight(), herVec.at(vecH)->getWeight()) && !herVec.at(vecH)->hide())
            {
                //Löschen des Dinos + auffülen der hunger variable
                karVec.at(vecK)->setStomachLevel(2);
                herVec.erase(herVec.begin() + vecH);
            }
            else
            {
                //Runterzählen der hunger Variable um 1 wenn 0 dann Karnivor Tot
                karVec.at(vecK)->reduceStomachLevel(1);
                if (karVec.at(vecK)->getStomachLevel() <= 0)
                    karVec.erase(karVec.begin() + vecK);
            }
        }
    }
}

void Utils::breed(std::vector<Karnivoren*> &karVec, std::vector<Herbivoren*> &herVec)
{
    for (auto &vecK : karVec)
    {
        if (vecK->breed())
        {
            //neuen dino erstellen
            int weight = vecK->getWeight() / 100 * 20;
            std::string race = vecK->getRace();
            auto* kar = new Karnivoren(weight, race);
            karVec.push_back(kar);
        }
    }
    for (auto &vecH : herVec)
    {
        if (vecH->breed())
        {
            //neuen dino erstellen
            int weight = vecH->getWeight() / 100 * 20;
            std::string race = vecH->getRace();
            auto* her = new Herbivoren(weight, race);
            herVec.push_back(her);
        }
    }
}
