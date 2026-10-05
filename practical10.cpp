#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;
}

int main() {
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<Edge> edges(e);

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int total = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (Edge edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            cout << edge.u << " - " << edge.v
                 << " = " << edge.w << endl;

            total += edge.w;
            unite(edge.u, edge.v);
        }
    }

    cout << "\nMinimum Cost = " << total << endl;

    return 0;
}
