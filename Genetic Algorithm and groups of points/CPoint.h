//
// Created by lenar on 19.01.2025.
//

#ifndef CPOINT_H
#define CPOINT_H

#include <cmath>
#include <vector>

using namespace std;

class CPoint {
public:
    void vAddCoordinate(double dCoordinate);
    double dCalculateDistance(const CPoint& cOther) const;

private:
    const double d_WRONG_DISTANCE_VALUE = -1;

    vector<double> v_coordinates;
};



#endif //CPOINT_H
