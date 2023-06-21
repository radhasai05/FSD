#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int knapSack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);
    int n = items.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (W >= items[i].weight) {
            ans += items[i].value;
            W -= items[i].weight;
        } else {
            ans += W * ((double)items[i].value / items[i].weight);
            break;
        }
    }
    return ans;
}

int main() {
    int W, n;
    cout << "Enter the capacity of knapsack: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }
    cout << "Maximum value that can be put in a knapsack of capacity " << W << " is: " << knapSack(W, items) << endl;
    return 0;
}
