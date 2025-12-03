#include "Graph.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

Graph::Graph() : n(0) {}

void Graph::loadFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Error: cannot open file!\n";
        return;
    }

    int u, v, w;
    int maxV = 0;
    vector<tuple<int, int, int>> edges;

    while (fin >> u >> v >> w) {
        edges.emplace_back(u, v, w);
        maxV = max(maxV, max(u, v));
    }
    fin.close();

    n = maxV;
    const int INF = 1e9;
    W.assign(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) W[i][i] = 0;

    for (auto& e : edges) {
        int a = get<0>(e);
        int b = get<1>(e);
        int c = get<2>(e);

        W[a][b] = c;
        W[b][a] = c;
    }
}
