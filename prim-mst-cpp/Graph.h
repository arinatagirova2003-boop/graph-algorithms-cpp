#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include "Edge.h"

class Graph {
private:
    int n;
    std::vector<Edge> edges;
    std::vector<std::vector<int>> W;

public:
    Graph();

    void loadFromFile(const std::string& filename);
    void buildWeightMatrix();
    void printGraphInfo() const;
    void runPrim() const;
};

#endif

