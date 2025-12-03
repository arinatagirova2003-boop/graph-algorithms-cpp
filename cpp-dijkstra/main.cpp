#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"

using namespace std;

int main() {
    Graph g;
    g.loadFromFile("input.txt");

    int start, end;
    cout << "Enter start vertex: ";
    cin >> start;
    cout << "Enter end vertex: ";
    cin >> end;

    int dist = 0;
    auto path = Dijkstra::run(g.getMatrix(), g.getN(), start, end, dist);

    cout << "\nShortest path using Dijkstra:\n";

    if (path.empty()) {
        cout << "No path exists.\n";
        return 0;
    }

    for (int i = 0; i + 1 < (int)path.size(); i++)
        cout << path[i] << " -> " << path[i + 1] << "\n";

    cout << "Total distance = " << dist << "\n";

    return 0;
}
