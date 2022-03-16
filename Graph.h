#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <random>

class Graph {
protected:
    std::vector<std::vector<int>> g;

public:
    virtual void print();
    int num_cc();
    void percolate_nodes(double q);
    void percolate_edges(double q);

private:
    void dfs (int v, std::vector<bool> &visited);
};
