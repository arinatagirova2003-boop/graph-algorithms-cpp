#ifndef DSU_H
#define DSU_H

#include <vector>

class DSU {
private:
    std::vector<int> parent, rnk;

public:
    DSU(int n);
    int findSet(int v);
    void unionSet(int a, int b);
};

#endif

