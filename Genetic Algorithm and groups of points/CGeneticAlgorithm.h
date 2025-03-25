//
// Created by lenar on 19.01.2025.
//

#ifndef CGENETICALGORITHM_H
#define CGENETICALGORITHM_H

#include "CGroupingEvaluator.h"
#include "CIndividual.h"
using namespace std;

class CGeneticAlgorithm {
public:
    CGeneticAlgorithm(int i_popsize, double d_crosspro, double d_mutpro, const CGroupingEvaluator* pc_evaluator);
    ~CGeneticAlgorithm();

    void vRun(int i_cyclecnt);

    double dGetBestFitness();
    vector<int> viGetBestGenes();

private:
    void vInitialize();
    void vCross();
    void vMutate();
    void vAssess();
    void vClear();
    void vCheckVars();
    void vClearBest();
    CIndividual* cCompetition();
    CIndividual* cTrioFight();
    int i_popsize;
    double d_crosspro;
    double d_mutpro;

    double d_bestresult;
    vector<int> vi_bestgentype;

    const CGroupingEvaluator* pc_evaluator;
    vector<CIndividual*> vpc_population;

    mt19937 c_randomengine;
};



#endif //CGENETICALGORITHM_H
