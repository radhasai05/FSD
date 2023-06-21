#include <iostream>
#include <vector>
using namespace std;

void printSubset(const vector<int>& subset) {
    for (int i = 0; i < subset.size(); i++) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

void findSubset(const vector<int>& S, int d, vector<int>& subset, int i) {
    if (d == 0) { // base case: subset sum found
        printSubset(subset);
        return;
    }
    if (i == S.size()) { // base case: subset sum not possible
        return;
    }
    // exclude the current element
    findSubset(S, d, subset, i+1);
    // include the current element
    subset.push_back(S[i]);
    findSubset(S, d-S[i], subset, i+1);
    subset.pop_back(); // backtrack
}

int main() {
    int n;
    cout << "Enter the size of the set: ";
    cin >> n;
    vector<int> S(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    int d;
    cout << "Enter the target sum: ";
    cin >> d;
    vector<int> subset;
    findSubset(S, d, subset, 0);
    return 0;
}