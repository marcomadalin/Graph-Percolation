#include "Graph.h"

void Graph::print() {
    for (int i = 0; i < this->g.size(); ++i) {
        std::cout << "Adj(" << i << ") : ";
        for (int j = 0; j < this->g[i].size(); ++j) std::cout << this->g[i][j] << " ";
        std::cout << std::endl;
    }
}

int Graph::num_cc() {
    int count = 0;
    std::vector<bool> visited(this->g.size(),false);

    for (int v = 0; v < g.size(); ++v) {
        if (!visited[v]){
            dfs(v,visited);
            ++count;
        }
    }
    return count;
}

void Graph::percolate_nodes(double q) {
    std::vector<int> nodes_org;
    std::map<int,int> remaing_nodes;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    int new_node = 0;

    for (int i = 0; i < g.size(); ++i) {
        if (dis(gen) > q) {
            nodes_org.push_back(i);
            remaing_nodes.emplace_hint(remaing_nodes.end(), i, new_node);
            ++new_node;
        }
    }
    std::vector<std::vector<int>> g_per(nodes_org.size());
    std::map<int,int>::iterator it;

    for (int i = 0; i < g_per.size(); ++i) {
        for (int j = 0; j < g[nodes_org[i]].size(); ++j) {
            it = remaing_nodes.find(g[nodes_org[i]][j]);
            if (it != remaing_nodes.end()) g_per[i].push_back(it->second);
        }
    }
    this->g = g_per;
}
void Graph::percolate_edges(double q) {
    std::vector<std::vector<int>> g_per(g.size());
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);


    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j] < i) {
                for (int k = 0; k < g_per[g[i][j]].size(); ++k) {
                    if (g_per[g[i][j]][k] == i) {
                        g_per[i].push_back(g[i][j]);
                        break;
                    }
                }
            }
            else if (dis(gen) > q) g_per[i].push_back(g[i][j]);
        }
    }
    this->g = g_per;
}

void Graph::dfs(int v, std::vector<bool> &visited) {
    visited[v] = true;
    for (int w = 0; w < this->g[v].size(); ++w) {
        if (!visited[this->g[v][w]]) dfs(this->g[v][w], visited);
    }
}

