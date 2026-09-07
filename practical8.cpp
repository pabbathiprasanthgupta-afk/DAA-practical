#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void DFS(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor])
            DFS(neighbor);
    }
}

void BFS(int start) {
    vector<bool> vis(graph.size(), false);
    queue<int> q;

    vis[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    graph.resize(vertices);
    visited.resize(vertices, false);

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    cout << "\nBFS Traversal: ";
    BFS(start);

    return 0;
}
