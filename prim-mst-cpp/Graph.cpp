#include "Graph.h"
#include "Prim.h"
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

    const int INF = 1e9;

    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int j = 1; j <= n; j++) {
            if (W[i][j] == INF) cout << "inf ";
            else cout << W[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Graph::runPrim() const {
    int total = 0;
    auto mst = Prim::run(W, n, total);

    cout << "MST edges (Prim):\n";
    for (auto& p : mst)
        cout << p.first << " - " << p.second
        << " : " << W[p.first][p.second] << "\n";

    cout << "\nTotal MST weight = " << total << "\n";
}
