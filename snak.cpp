#include <iostream>
#include <cstring>
using namespace std;

int knapsack(int capacity, int weights[], int values[], int num_items)
{
    int dp[num_items+1][capacity+1];
    memset(dp, 0, sizeof(dp)); 

    for (int i = 1; i <= num_items; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (weights[i-1] <= j)
            {
                dp[i][j] = max(values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[num_items][capacity];
}

int main()
{
    int capacity, num_items;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    cout << "Enter the number of items: ";
    cin >> num_items;

    int weights[num_items], values[num_items];
    cout << "Enter the weights and values of each item:" << endl;
    for (int i = 0; i < num_items; i++)
    {
        cin >> weights[i] >> values[i];
    }

    int max_value = knapsack(capacity, weights, values, num_items);
    cout << "The maximum value that can be obtained is: " << max_value << endl;

    return 0;
}
