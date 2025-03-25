#include <bits/stdc++.h>
#include "CIndividual.h"
#include "CGeneticAlgorithm.h"
using namespace std;

CPoint stworz(double x){
    CPoint a;
    a.vAddCoordinate(x);
    a.vAddCoordinate(x);
    return a;
}

int main(){
    vector<CPoint> punkty;
    for(int i=0; i<10; i++){
        punkty.push_back(stworz(i));
    }
    CGroupingEvaluator* pc_eva1 = new CGroupingEvaluator(3, punkty);
    CGeneticAlgorithm gene1(10, 0.7, 0.4, pc_eva1);
    CGeneticAlgorithm gene2(100, 0.8, 0.2, pc_eva1);
    gene1.vRun(5);
    cout << gene1.dGetBestFitness() << "\n";
    gene2.vRun(500);
    cout << gene2.dGetBestFitness();
}
