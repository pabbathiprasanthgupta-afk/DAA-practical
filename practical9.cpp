#include <iostream>
using namespace std;

#define V 5
#define INF 9999

void prim(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    // Initialize values
    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        mstSet[i] = false;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1;

    // Find MST
    for (int count = 0; count < V - 1; count++)
    {
        int min = INF;
        int u = -1;

        // Find minimum key vertex
        for (int v = 0; v < V; v++)
        {
            if (!mstSet[v] && key[v] < min)
            {
                min = key[v];
                u = v;
            }
        }

        mstSet[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print MST
    cout << "Edge \tWeight\n";

    int total = 0;

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        total += graph[i][parent[i]];
    }

    cout << "\nTotal weight of MST = " << total << endl;
}

int main()
{
    int graph[V][V] =
    {
        {0, 2, 3, 6, 0},
        {2, 0, 1, 4, 5},
        {3, 1, 0, 5, 0},
        {6, 4, 5, 0, 2},
        {0, 5, 0, 2, 0}
    };

    prim(graph);

    return 0;
}
