#include "Graph.h"
#include "DSU.h"
#include <fstream>
#include <iostream>
#include <algorithm>

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
    while (fin >> u >> v >> w) {
        edges.push_back({ u, v, w });
        maxV = max({ maxV, u, v });
    }
    fin.close();
    n = maxV;
}

void Graph::buildWeightMatrix() {
    const int INF = 1e9;

    W.assign(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) W[i][i] = 0;

    for (auto& e : edges) {
        W[e.u][e.v] = e.w;
        W[e.v][e.u] = e.w;
    }
}

void Graph::printGraphInfo() const {
    cout << "Number of vertices: " << n << "\n";
    cout << "Number of edges: " << edges.size() << "\n\n";

    cout << "All edges:\n";
    for (auto& e : edges)
        cout << e.u << " - " << e.v << " : " << e.w << "\n";
    cout << "\n";

    cout << "Weight matrix:\n    ";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << "\n";

    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int j = 1; j <= n; j++) {
            if (W[i][j] == 1e9) cout << "? ";
            else cout << W[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Graph::runKruskal() const {
    vector<Edge> E = edges;
    sort(E.begin(), E.end(), [](auto& a, auto& b) { return a.w < b.w; });

    DSU dsu(n);
    vector<Edge> mst;
    int total = 0;

    for (auto& e : E) {
        if (dsu.findSet(e.u) != dsu.findSet(e.v)) {
            dsu.unionSet(e.u, e.v);
            mst.push_back(e);
            total += e.w;
        }
    }

    cout << "MST edges:\n";
    for (auto& e : mst)
        cout << e.u << " - " << e.v << " : " << e.w << "\n";

    cout << "\nTotal MST weight = " << total << "\n";
}
