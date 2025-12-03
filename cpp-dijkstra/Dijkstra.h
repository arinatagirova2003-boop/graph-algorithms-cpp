#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>

class Dijkstra {
public:
    static std::vector<int> run(
        const std::vector<std::vector<int>>& W,
        int n, int start, int end, int& dist
    );
};

#endif

