#include "CIndividual.h"

CIndividual :: CIndividual(const double d_crosspro, const double d_mutpro, const CGroupingEvaluator* c_evaluator)
    : c_evaluator(c_evaluator), d_mutpro(d_mutpro), d_crosspro(d_crosspro) {
}

CIndividual :: CIndividual(const CIndividual &c_other)
    : d_crosspro(d_crosspro), d_mutpro(c_other.d_mutpro), vi_gentype(c_other.vi_gentype), c_evaluator(c_other.c_evaluator) {
}

CIndividual :: ~CIndividual() {
    c_evaluator = nullptr;
}

void CIndividual :: vInitialize(){
    random_device c_seedgenerator;
	c_randomengine.seed(c_seedgenerator());
    uniform_int_distribution<int> c_grouprand(c_evaluator->iGetLowerBound(), c_evaluator->iGetUpperBound());
    for(int i=0; i<c_evaluator->iGetNumberOfPoints(); i++){
        vi_gentype.push_back(c_grouprand(c_randomengine));
    }
}

double CIndividual :: dFitness(){
    return c_evaluator->dEvaluate(vi_gentype);
}

vector<CIndividual*> CIndividual :: cEvolution(const CIndividual& c_parent){
    uniform_int_distribution<int> c_genrand(0, (c_evaluator->iGetUpperBound()-1));
    uniform_real_distribution<double> c_chancerand(0, 1);
    vector<CIndividual*> vpc_kids;
    if(c_chancerand(c_randomengine) <= d_crosspro){
        vpc_kids.push_back( new CIndividual(d_mutpro, d_mutpro, c_evaluator));
        vpc_kids.push_back( new CIndividual(d_mutpro, d_mutpro, c_evaluator));
        int i_breakpoint = c_genrand(c_randomengine);
        vector<int> vi_songentype, vi_daugentype;
        for(int i=0; i<=i_breakpoint; i++){
            vpc_kids[0]->vi_gentype.push_back(vi_gentype[i]);
            vpc_kids[1]->vi_gentype.push_back(c_parent.vi_gentype[i]);
        }
        for(int i=i_breakpoint+1; i<c_evaluator->iGetNumberOfPoints(); i++){
            vpc_kids[0]->vi_gentype.push_back(c_parent.vi_gentype[i]);
            vpc_kids[1]->vi_gentype.push_back(vi_gentype[i]);
        }
    } else {
        vpc_kids.push_back(new CIndividual(*this));
        vpc_kids.push_back(new CIndividual(c_parent));
    }
    return vpc_kids;
}

void CIndividual :: vMutation(){
    uniform_int_distribution<int> c_grouprand(c_evaluator->iGetLowerBound(), c_evaluator->iGetUpperBound());
    uniform_real_distribution<double> c_chancerand(0, 1);
    for(int i=0; i<c_evaluator->iGetNumberOfPoints(); i++){
        if(c_chancerand(c_randomengine) <= d_mutpro){
            vi_gentype[i] = c_grouprand(c_randomengine);
        }
    }
}

vector<int>& CIndividual::viGetGenes() {
    return vi_gentype;
}


string CIndividual :: sString(){
    string s_result = "OSOBNIK: ";
    for(int i=0; i<c_evaluator->iGetNumberOfPoints(); i++){
        s_result += to_string(vi_gentype[i]) + " ";
    }
    return s_result;
}



