#include "Dijkstra.h"
#include <vector>
#include <limits>
#include <iostream>

using namespace std;

vector<int> Dijkstra::run(
    const vector<vector<int>>& W,
    int n, int start, int end, int& dist
) {
    const int INF = 1e9;

    vector<int> d(n + 1, INF);
    vector<bool> used(n + 1, false);
    vector<int> parent(n + 1, -1);

    d[start] = 0;

    for (int i = 1; i <= n; i++) {
        int v = -1;
        for (int j = 1; j <= n; j++)
            if (!used[j] && (v == -1 || d[j] < d[v]))
                v = j;

        if (d[v] == INF)
            break;

        used[v] = true;

        for (int to = 1; to <= n; to++) {
            if (W[v][to] >= INF) continue;

            int newDist = d[v] + W[v][to];
            if (newDist < d[to]) {
                d[to] = newDist;
                parent[to] = v;
            }
        }
    }

    dist = d[end];

    vector<int> path;
    if (dist == INF)
        return path;

    for (int v = end; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}
