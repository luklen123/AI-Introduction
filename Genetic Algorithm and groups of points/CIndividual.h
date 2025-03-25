//
// Created by lenar on 19.01.2025.
//

#ifndef CINDIVIDUAL_H
#define CINDIVIDUAL_H

#include "CGroupingEvaluator.h"
#include <bits/stdc++.h>

using namespace std;


class CIndividual {
public:
    CIndividual(double d_crosspro, double d_mutpro, const CGroupingEvaluator* c_evaluator);
    CIndividual(const CIndividual& c_other);
    ~CIndividual();

    vector<int>& viGetGenes();
    void vInitialize();
    double dFitness();
    vector<CIndividual*> cEvolution(const CIndividual& c_parent);
    void vMutation();
    string sString();

private:
    const double d_mutpro;
    const double d_crosspro;
    vector<int> vi_gentype;
    const CGroupingEvaluator* c_evaluator;
    mt19937 c_randomengine;
};

#endif //CINDIVIDUAL_H
