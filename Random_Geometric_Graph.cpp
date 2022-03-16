#include "Random_Geometric_Graph.h"

 Random_Geometric_Graph::Random_Geometric_Graph(int n, double r) {
    this->g = std::vector<std::vector<int>> (n);
    std::vector<std::pair<double,double>> values(n);


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < n; ++i) {
        values[i].first = dis(gen);
        values[i].second = dis(gen);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (distance(values[i], values[j]) <= r) {
                this->g[i].push_back(j);
                this->g[j].push_back(i);
            }
        }
    }
}


double Random_Geometric_Graph::distance(std::pair<double, double> w, std::pair<double, double> v) {
    return sqrt(pow(w.first - v.first, 2) + pow(w.second - v.second, 2) * 1.0);
}
