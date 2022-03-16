#pragma once

#include <cmath>
#include "Graph.h"


class Random_Geometric_Graph: public Graph {
public:
    Random_Geometric_Graph(int n, double r);

private:
    double distance(std::pair<double, double> w, std::pair<double, double> v);
};