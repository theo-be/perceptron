#include <iostream>
#include <vector>

#include "simple/PerceptronSimple.h"

int main() {


    auto *entrees = new std::vector<std::vector<int>*>(4, nullptr);
    for (int i = 0; i < 4; i++) {
        entrees->at(i) = new std::vector<int>(4, 0);

    }

    entrees->at(0)->at(0) = 0;
    entrees->at(0)->at(1) = 0;

    entrees->at(1)->at(0) = 1;
    entrees->at(1)->at(1) = 0;

    entrees->at(2)->at(0) = 0;
    entrees->at(2)->at(1) = 1;

    entrees->at(3)->at(0) = 1;
    entrees->at(3)->at(1) = 1;

    auto *sorties = new std::vector<int>(4, 0);

    sorties->at(0) = 0;
    sorties->at(1) = 0;
    sorties->at(2) = 0;
    sorties->at(3) = 1;



    PerceptronSimple perceptronSimple;
    perceptronSimple.setEntrees(entrees);
    perceptronSimple.setSorties(sorties);

    std::cout << "lancement du perceptron simple" << std::endl;

    perceptronSimple.lancer();

    std::cout << "fin du perceptron simple, " << perceptronSimple.getNbIterations() << " iterations" << std::endl;
    auto poids = perceptronSimple.getPoids();
    std::cout << poids->size();
    std::cout << "poids:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << poids->at(i) << ", ";
    }
    std::cout << std::endl;


    for (int i = 0; i < 4; i++) {
        delete entrees->at(i);
    }
    delete entrees;

    return 0;
}
