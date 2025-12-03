#ifndef PRIM_H
#define PRIM_H

#include <vector>

class Prim {
public:
    static std::vector<std::pair<int, int>>
        run(const std::vector<std::vector<int>>& W, int n, int& totalWeight);
};

#endif

