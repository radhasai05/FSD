#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 20;

int n, cnt;
int graph[MAXN][MAXN];
vector<int> path;
bool visited[MAXN];

void findHamiltonianCycle(int u) {
    if (path.size() == n && graph[u][path[0]]) {
        // Found a Hamiltonian Cycle
        cnt++;
        cout << "Hamiltonian Cycle " << cnt << ": ";
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
        cout << path[0] << endl;
        return;
    }
    for (int v = 0; v < n; v++) {
        if (graph[u][v] && !visited[v]) {
            visited[v] = true;
            path.push_back(v);
            findHamiltonianCycle(v);
            visited[v] = false;
            path.pop_back();
        }
    }
}

void findAllHamiltonianCycles() {
    cnt = 0;
    path.clear();
    for (int i = 0; i < n; i++) {
        visited[i] = true;
        path.push_back(i);
        findHamiltonianCycle(i);
        visited[i] = false;
        path.pop_back();
    }
}

int main() {
    // Input the Graph
    cout << "Enter the number of vertices (maximum " << MAXN << "): ";
    cin >> n;
    cout << "Enter the adjacency matrix (0/1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    // Find all Hamiltonian Cycles
    findAllHamiltonianCycles();
    if (cnt == 0)
        cout << "No Hamiltonian Cycles found.\n";
    else
        cout << "Total Hamiltonian Cycles found: " << cnt << endl;
    return 0;
}