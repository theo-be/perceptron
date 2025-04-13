
#ifndef PERCEPTRON_SIMPLE
#define PERCEPTRON_SIMPLE

#include <list>
#include <vector>

class PerceptronSimple {
public:

    PerceptronSimple();

    std::vector<float> *getPoids();

    void setEntrees(std::vector<std::vector<int>*> *);
    void setSorties(std::vector<int>*);
    void setTauxApprentissage(float);
    void initPoids();
    void execAlgo();
    void setNbIterationsMax(int itMax);
    void lancer();





private:

    int evaluerSortie(int);
    void correctionPoids(int, int);


    int m_tailleDataset;
    int m_nbEntrees;
    int m_nbSorties;

    int m_nbErreurs;
    int m_nbItMax;
    float m_tauxApprentissage;

    std::vector<std::vector<int>*> *m_entrees;
    std::vector<float> *m_poids;
    std::vector<int> *m_sorties;



};

#endif
