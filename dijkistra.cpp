#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 999999

void dijkstra(vector<vector<int>>& graph, int n, int src) {
    vector<int> dist(n, INF);
    vector<int> prev(n, -1);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1, best = INF;

        // Find unvisited node with minimum distance
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < best) {
                u = v;
                best = dist[v];
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < n; v++) {
            int w = graph[u][v];

            if (w != 0 && !visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
            }
        }
    }

    cout << "\nNode  Distance  Path\n";

    for (int v = 0; v < n; v++) {
        cout << v << "     ";

        if (dist[v] == INF) {
            cout << "INF       No path\n";
        }
        else {
            cout << dist[v] << "         ";

            vector<int> path;
            int x = v;

            while (x != -1) {
                path.push_back(x);
                x = prev[x];
            }

            reverse(path.begin(), path.end());

            for (int i = 0; i < path.size(); i++) {
                cout << path[i];

                if (i != path.size() - 1)
                    cout << " -> ";
            }

            cout << endl;
        }
    }
}

int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the cost adjacency matrix (0 = no edge):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int src;

    cout << "Enter source node (0 to " << n - 1 << "): ";
    cin >> src;

    dijkstra(graph, n, src);

    return 0;
}
