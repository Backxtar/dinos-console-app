#include <iostream>
#include "Dinosaurier.h"
#include "Herbivoren.h"
#include "Karnivoren.h"
#include "vector"

std::vector<Herbivoren> herVec;
std::vector<Karnivoren> karVec;

void passingTime(){

    //Variablen
    int timePasses;

    //Months Simulating
    while (true){
        std::cout << "Bitte geben sie die Anzahl an Monaten an die Simuliert werden sollen : ";
        std::cin >> timePasses;
        if(timePasses > 0) break;
    }

    //Growing Steps + Die at an old age
    for (int i = 0; i <= timePasses ; ++i) {
        for (auto &vecH : herVec) {
            vecH.growingUp();

                 if (vecH.getWeight() == vecH.getMaxWeight() && vecH.die()){
                    //Dino Löschen
                }

            }
        }
        for (auto &vecK : karVec) {
            vecK.growingUp();
            if (vecK.getWeight() == vecK.getMaxWeight() && vecK.die()){
                //Dino Löschen
            }
        }

    //Simulating the hunts + Stomach-Level reduce
    for (int vecK = 0; vecK < karVec.size() ; ++vecK) {
        for (int vecH = 0; vecH < herVec.size() ; ++vecH) {
            if (karVec.at(vecK).hunt(vecK,vecH) && !herVec.at(vecH).hide()){
                //Löschen des Dinos + auffülen der hunger variable
                karVec.at(vecK).setStomachLevel(2);
            }else{
                //Runterzählen der hunger Variable um 1 wenn 0 dann Karnivor Tot
                karVec.at(vecK).reduceStomachLevel(1);
                if (karVec.at(vecK).getStomachLevel() <= 0){
                    //Delet
                }
            }
        }
    }

    //Breed
    for (auto &vecK : karVec) {
        if (vecK.breed()) {
            Karnivoren* kar = new Karnivoren();
            //neuen dino erstellen
        }
    }
    for (auto &vecH : herVec) {
        if (vecH.breed()) {
            //neuen dino erstellen
        }
    }

}



int main() {

    passingTime();

}
