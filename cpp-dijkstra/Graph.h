#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
private:
    int n;
    std::vector<std::vector<int>> W;

public:
    Graph();
    void loadFromFile(const std::string& filename);
    void printWeightMatrix() const;

    int getN() const { return n; }
    const std::vector<std::vector<int>>& getMatrix() const { return W; }
};

#endif

