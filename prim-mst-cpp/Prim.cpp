#include "Prim.h"
#include <limits>
#include <vector>

using namespace std;

vector<pair<int, int>> Prim::run(const vector<vector<int>>& W, int n, int& totalWeight)
{
    const int INF = 1e9;
    vector<int> key(n + 1, INF);
    vector<bool> used(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[1] = 0;

    for (int i = 1; i <= n; i++) {

        int v = -1;
        for (int j = 1; j <= n; j++)
            if (!used[j] && (v == -1 || key[j] < key[v]))
                v = j;

        used[v] = true;

        for (int to = 1; to <= n; to++) {

            if (to == v) continue;

            if (W[v][to] < key[to]) {
                key[to] = W[v][to];
                parent[to] = v;
            }
        }
    }

    vector<pair<int, int>> mst;
    totalWeight = 0;

    for (int v = 2; v <= n; v++) {
        mst.push_back({ parent[v], v });
        totalWeight += W[parent[v]][v];
    }

    return mst;
}
