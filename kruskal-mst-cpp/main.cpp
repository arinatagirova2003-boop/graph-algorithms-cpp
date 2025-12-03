#include "Graph.h"

int main() {
    Graph g;

    g.loadFromFile("input.txt");
    g.buildWeightMatrix();

    g.printGraphInfo();
    g.runKruskal();

    return 0;
}
