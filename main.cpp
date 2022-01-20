#include <iostream>
#include "Dinosaurier.h"
#include "Herbivoren.h"
#include "Karnivoren.h"
#include "vector"

void passingTime(){
    int timePasses;

    bool check= true;

    while (check){
        cout << "Bitte geben sie die Anzahl an Monaten an die Simuliert werden sollen : ";
        cin >> timePasses;
        if(timePasses >= 0){
            ckeck = false;
        }
    }

    for (int i = 0; i <= timePasses ; ++i) {
        for (int vecH = 0; vecH < Dinosaurier::herVec.size() ; ++vecH) {
            Dinosaurier::herVec.at(vecH).growingUp;
        }
        for (int vecK = 0; vecK < Dinosaurier::karVec.size(); ++vecK) {
            Dinosaurier::karVec.at(vecK).growingUp;
        }

        for (int vecHBreed = 0; vecHBreed < Dinosaurier::herVec.size(); ++vecHBreed) {
            Dinosaurier::herVec.at(vecHBreed).breed;
        }

        for (int vecKBreed = 0; vecKBreed < Dinosaurier::herVec.size(); ++vecKBreed) {
            Dinosaurier::herVec.at(vecKBreed).breed;
        }

    }

}


int main() {

    passingTime();

}
