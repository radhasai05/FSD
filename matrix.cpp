#include <iostream>
#include <climits>
using namespace std;
void dijkstra(int** adj, int n, int src, int* dist, bool* visited) {
    int unvis, min_dist;
    for (int i = 0; i < n; i++) {
        dist[i] = adj[src - 1][i];
        visited[i] = false;
    }
    visited[src - 1] = true;
    for (int i = 1; i < n; i++) {
        min_dist = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                unvis = j;
                min_dist = dist[j];
            }
        }
        visited[unvis] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[unvis] + adj[unvis][v] < dist[v]) {
                dist[v] = dist[unvis] + adj[unvis][v];
            }
        }
    }
}

int main() {
    int n, src;
    cout << "Enter Number of Vertices: ";
    cin >> n;
    int** adj = new int*[n];
    for (int i = 0; i < n; i++) {
        adj[i] = new int[n];
    }
    cout << "Enter Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    cout << "Enter Source vertex: ";
    cin >> src;
    int dist[n];
    bool visited[n];
    dijkstra(adj, n, src, dist, visited);
    for (int i = 0; i < n; i++) {
        if ((src - 1) == i) {
            continue;
        }
        cout << "Shortest Distance from " << src << " to " << (i + 1) << " is " << dist[i] << endl;
    }
    return 0;
}