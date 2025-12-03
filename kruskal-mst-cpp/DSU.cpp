#include "DSU.h"

DSU::DSU(int n) {
    parent.resize(n + 1);
    rnk.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int DSU::findSet(int v) {
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

void DSU::unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (rnk[a] < rnk[b]) std::swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
    }
}
