#include "CGeneticAlgorithm.h"
#include "Constants.h"

CGeneticAlgorithm :: CGeneticAlgorithm(int i_popsize, double d_crosspro, double d_mutpro, const CGroupingEvaluator* pc_evaluator){
    this->i_popsize=i_popsize;
    this->d_crosspro=d_crosspro;
    this->d_mutpro = d_mutpro;
    vCheckVars();
    this->pc_evaluator=pc_evaluator;
    d_bestresult = CONST_D_MAX_DOUBLE;
    random_device c_seedgenerator;
    c_randomengine.seed(c_seedgenerator());
}

void CGeneticAlgorithm :: vCheckVars() {
    if (i_popsize <= 0) i_popsize = CONST_I_POPSIZE;
    if (i_popsize%2 == 1) i_popsize++;
    if (d_crosspro < 0 || d_crosspro > 1.0) d_crosspro = CONST_D_CROSSPRO;
    if (d_mutpro < 0 || d_mutpro > 1.0) d_mutpro = CONST_D_MUTPRO;
}

double CGeneticAlgorithm :: dGetBestFitness() {
    return d_bestresult;
}

vector<int> CGeneticAlgorithm :: viGetBestGenes() {
    return vi_bestgentype;
}

void CGeneticAlgorithm :: vRun(int i_cyclecnt){
    vClearBest();
    vInitialize();
    while(max(i_cyclecnt--, 0)){
        vCross();
        vAssess();
        vMutate();
        vAssess();
    }
    vClear();
}

CIndividual* CGeneticAlgorithm :: cTrioFight() {
    CIndividual* pc_cad1 = new CIndividual(d_crosspro, d_mutpro, pc_evaluator);
    CIndividual* pc_cad2 = new CIndividual(d_crosspro, d_mutpro, pc_evaluator);
    CIndividual* pc_cad3 = new CIndividual(d_crosspro, d_mutpro, pc_evaluator);
    pc_cad1->vInitialize();
    pc_cad2->vInitialize();
    pc_cad3->vInitialize();
    double d_fitcad1 = pc_cad1->dFitness();
    double d_fitcad2 = pc_cad2->dFitness();
    double d_fitcad3 = pc_cad3->dFitness();
    double d_minimalfit = min({d_fitcad1, d_fitcad2, d_fitcad3});
    if (d_minimalfit == d_fitcad1) {
        delete pc_cad2;
        delete pc_cad3;
        return pc_cad1;
    }
    if (d_minimalfit == d_fitcad2) {
        delete pc_cad1;
        delete pc_cad3;
        return pc_cad2;
    }
    if (d_minimalfit == d_fitcad3) {
        delete pc_cad1;
        delete pc_cad2;
        return pc_cad3;
    }
}

void CGeneticAlgorithm :: vInitialize(){
    for(int i=0; i<i_popsize; i++){
        //vpc_population.push_back(new CIndividual(d_crosspro, d_mutpro, pc_evaluator));
        vpc_population.push_back(cTrioFight());
        //vpc_population[i]->vInitialize();
    }
}

void CGeneticAlgorithm :: vCross(){
    vector<CIndividual*> vpc_newpopulation;
    int i_newborns = 0;
    CIndividual* pc_parent1 = nullptr;
    CIndividual* pc_parent2 = nullptr;
    while(i_newborns < i_popsize){
        pc_parent1 = cCompetition();
        pc_parent2 = cCompetition();
        vector<CIndividual*> vpc_kids = pc_parent1->cEvolution(*pc_parent2);
        //vector<CIndividual*> vpc_kids = cCompetition()->cEvolution(*cCompetition());
        for(int i=0; i<vpc_kids.size(); i++) vpc_newpopulation.push_back(vpc_kids[i]);
        i_newborns += 2;
    }
    for(int i=0; i<vpc_population.size(); i++){
        delete vpc_population[i];
        vpc_population[i] = vpc_newpopulation[i];
    }
    vpc_newpopulation.clear();
}

CIndividual* CGeneticAlgorithm :: cCompetition() {
    uniform_int_distribution<int> c_indrand(0, i_popsize-1);
    CIndividual* pc_cand1 = nullptr;
    CIndividual* pc_cand2 = nullptr;
    int i_cand1 = 0;
    int i_cand2 = 0;
    i_cand1 = c_indrand(c_randomengine);
    pc_cand1 = vpc_population[i_cand1];
    i_cand2 = c_indrand(c_randomengine);
    pc_cand2 = vpc_population[i_cand2];
    if (pc_cand1->dFitness() <= pc_cand2->dFitness()) return pc_cand1;
    return pc_cand2;
}

void CGeneticAlgorithm :: vAssess(){
    double d_actresult;
    for(int i=0; i<vpc_population.size(); i++){
        d_actresult = vpc_population[i]->dFitness();
        if(d_actresult < d_bestresult){
            d_bestresult = d_actresult;
            vi_bestgentype = vpc_population[i]->viGetGenes();
        }
    }
}

void CGeneticAlgorithm :: vMutate() {
    for(int i=0; i<vpc_population.size(); i++) {
        vpc_population[i]->vMutation();
    }
}

void CGeneticAlgorithm :: vClear() {
    for (int i=0; i<vpc_population.size(); i++) {
        delete vpc_population[i];
    }
    vpc_population.clear();
}

void CGeneticAlgorithm :: vClearBest() {
    d_bestresult = CONST_D_MAX_DOUBLE;
    vi_bestgentype.clear();
}

CGeneticAlgorithm :: ~CGeneticAlgorithm() {
}











