#include <iostream>
using namespace std;
int main() {
 int n;
 cout << "Enter Number of Vertices: ";
 cin >> n;
 int D[n + 1][n][n];
 cout << "Enter Distance Matrix:\n";
 for(int i = 0; i < n; i++) {
 for(int j = 0; j < n; j++) {
 cin >> D[0][i][j];
 }
 }
 for(int k = 1; k <= n; k++) {
 for(int i = 0; i < n; i++) {
 for(int j = 0; j < n; j++) {
 D[k][i][j] = min(D[k - 1][i][j], D[k - 1][i][k - 1] + D[k - 1][k - 1][j]);
 }
 }}
 cout << "floyds algoritm:\n";
 for(int i = 0; i < n; i++) {
 for(int j = 0; j < n; j++) {
 cout << D[n][i][j] << " ";
 }
 cout << endl;
 }
 return 0;
}

