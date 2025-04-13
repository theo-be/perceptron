
#include "PerceptronSimple.h"

#include <iostream>


PerceptronSimple::PerceptronSimple(): m_tailleDataset(0), m_nbEntrees(0), m_nbSorties(0), m_nbErreurs(0), m_nbItMax(10000), m_nbIterations(0), m_tauxApprentissage(0.1), m_entrees(
                                          nullptr), m_poids(nullptr), m_sorties(nullptr) {

}

void PerceptronSimple::setEntrees(std::vector<std::vector<int> *> *entrees) {
    m_entrees = entrees;
    m_tailleDataset = entrees->size();
    m_nbEntrees = entrees->at(0)->size();
}

void PerceptronSimple::setSorties(std::vector<int> *sorties) {
    m_sorties = sorties;
    m_nbSorties = sorties->size();
}

void PerceptronSimple::initPoids() {
    m_poids = new std::vector<float>(m_nbEntrees + 1, 0);
    std::cout << m_poids->size();
}

void PerceptronSimple::execAlgo() {
    initPoids();

    m_nbIterations = 0;
    do {
        m_nbIterations++;
        m_nbErreurs = 0;

        for (int i = 0; i < m_tailleDataset; i++) {
            int sortie = evaluerSortie(i);

            int erreur = m_sorties->at(i) - sortie;

            if (erreur) {
                // corriger les erreurs
                m_nbErreurs++;
                correctionPoids(i, sortie);
            }


        }
    } while (m_nbErreurs || m_nbIterations > m_nbItMax);

}

void PerceptronSimple::setNbIterationsMax(int itMax) {
    m_nbItMax = itMax;
}

void PerceptronSimple::lancer() {
    execAlgo();
}

int PerceptronSimple::evaluerSortie(int indiceDataset) {
    float potentiel = 0;

    potentiel += m_poids->at(0);

    for (int j = 0; j < m_nbEntrees; j++) {
        potentiel += m_entrees->at(indiceDataset)->at(j) * m_poids->at(j + 1);
    }

    int sortie = potentiel > 0;
    return sortie;
}

void PerceptronSimple::correctionPoids(int indiceDataset, int sortieEvaluee) {
    float poids = m_poids->at(0);
    float correctionPoids = poids + m_tauxApprentissage * (m_sorties->at(indiceDataset) - sortieEvaluee);
    m_poids->assign(0, correctionPoids);

    for (int k = 0; k < m_nbEntrees; k++) {
        poids = m_entrees->at(indiceDataset)->at(k);
        correctionPoids = poids + m_tauxApprentissage * (m_sorties->at(indiceDataset) - sortieEvaluee) * m_entrees->at(indiceDataset)->at(k);
        m_poids->assign(k + 1, correctionPoids);
    }
}

void PerceptronSimple::setTauxApprentissage(float taux) {
    m_tauxApprentissage = taux;
}

std::vector<float> *PerceptronSimple::getPoids() {
    return m_poids;
}

int PerceptronSimple::getNbIterations() const {
    return m_nbIterations;
}

