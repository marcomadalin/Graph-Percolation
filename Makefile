main: main.cpp Graph.cpp Graph.h Grid_Graph.cpp Grid_Graph.h Random_Geometric_Graph.cpp Random_Geometric_Graph.h

	g++ -o main main.cpp Graph.cpp Grid_Graph.cpp Random_Geometric_Graph.cpp

clean:
	rm main
