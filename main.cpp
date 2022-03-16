
#include <fstream>
#include "Grid_Graph.h"
#include "Random_Geometric_Graph.h"

using namespace std;

int main() {
    int type;
    ofstream fout("output.txt");
    ifstream fin("input.txt");

    std::cout << "Introduiu 0 per graf quadricula o 1 per geometric" << std::endl;
    while (fin >> type) {
        int percolation, size, iterations;
        double r, q;

        std::cout << "Introduiu la mida del graf" << std::endl;
        fin >> size;
        if (type == 1) {
            std::cout << "Introduiu el valor de r en el rang [0,1)" << std::endl;
            fin >> r;
        }
        std::cout << "Introduiu 0 percolacio per nodes o 1 per arestes" << std::endl;
        fin >> percolation;
        std::cout << "Introduiu el valor de q en el rang [0,1]" << std::endl;
        fin >> q;
        std::cout << "Introduiu el nombre d'iteracions" << std::endl;
        fin >> iterations;
       
	
	for (q; q < 1; q = q+0.001) {
		int transicions = 0;
        for (int i = 0; i < iterations; ++i) {
            Graph* g;
            if (type == 0) g = new Grid_Graph(size);
            else {
                g = new Random_Geometric_Graph(size, r);
                while (g->num_cc() > 1) {
                    r += 0.01;
                    free(g);
                    g = new Random_Geometric_Graph(size, r);
                }
                //fout << "r = " << r << endl;
            }
            //g->print();
            if (percolation == 0) g->percolate_nodes(q);
            else g->percolate_edges(q);
            //g->print();
           
			if (g->num_cc() > 1) ++transicions;
            free(g);
           
        }
        double probabilitat_transicio = (double)transicions/(double)iterations; 
        fout << probabilitat_transicio << endl;
        cout << q << endl;
        
	}
        std::cout << "Introduiu 0 per graf quadricula o 1 per geometric" << std::endl;
    }
    return 0;
}
