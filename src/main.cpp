#include "DiGraph.h"

#include <iostream>

int main() {

    DiGraph<int, double> g;
    g.addNode(0);
    g.addNode(1);
    g.addEdge(0, 1, 0.5);

    std::cout << g.getValue(0, 1);
}