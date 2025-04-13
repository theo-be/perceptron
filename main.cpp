#include <iostream>
#include <vector>

#include "simple/PerceptronSimple.h"

int main() {


    std::vector<std::vector<int>*> *entrees = new std::vector<std::vector<int>*>(10, 0);
    entrees->reserve(10);
    for (int i = 0; i < 10; i++) {
        entrees->at(i) = new std::vector<int>(2, 0);
    }

    std::vector<int> *sorties = new std::vector<int>(10, 0);

    PerceptronSimple perceptronSimple;
    perceptronSimple.setEntrees(entrees);
    perceptronSimple.setSorties(sorties);


    perceptronSimple.lancer();

    auto poids = perceptronSimple.getPoids();


    for (int i = 0; i < 10; i++) {
        delete entrees->at(i);
    }
    delete entrees;

    return 0;
}
