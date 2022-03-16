#include "Grid_Graph.h"

Grid_Graph::Grid_Graph(int n) {
    this->g = std::vector<std::vector<int>> (n*n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int index = i * n + j;
            if (j != n-1) g[index].push_back(index+1);
            if (j != 0) g[index].push_back(index-1);
            if (i != n-1) g[index].push_back(index+n);
            if (i != 0) g[index].push_back(index-n);
        }
    }
}
