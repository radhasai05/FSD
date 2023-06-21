#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 16; // Maximum number of cities

int n; // Number of cities
int dist[MAX_N][MAX_N]; // Distance between cities
int dp[1 << MAX_N][MAX_N]; // Dynamic programming array

// Function to compute the minimum cost to visit all cities starting from the given city
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) { // All cities have been visited
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1) { // Already computed
        return dp[mask][pos];
    }
    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // City not visited
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    memset(dp, -1, sizeof(dp)); // Initialize dynamic programming array
    int ans = tsp(1, 0); // Start at city 0
    cout << "the shortest path to visit all the cities and origin is: " << ans << endl;
    return 0;
}