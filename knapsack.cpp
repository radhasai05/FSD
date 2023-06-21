#include <iostream>
#include <algorithm>
using namespace std;
struct Item
{
   int value, weight;
};
bool compare(Item a, Item b)
{
   double r1, r2;
   r1 = a.value / a.weight;
   r2 = b.value / b.weight;
   return r1 > r2;
}
double knapsack(int W, Item arr[], int n)
{
   sort(arr, arr + n, compare);
   cout << "the sorted array will be:" << endl;
   for (int i = 0; i < n; i++)
      cout << "Weight " << arr[i].weight << " Value " << arr[i].value << endl;
   int cur_weight = 0;
   double final_val = 0.0;
   cout << endl;
   for (int i = 0; i < n; i++)
   {
      if (cur_weight + arr[i].weight <= W)
      {
         cur_weight += arr[i].weight;
         final_val += arr[i].value;
         cout << "Iteration No:" << i + 1 << " current weight = " << cur_weight << " remaining weight = " << W - cur_weight << endl;
      }
      else
      {
         int remain = W - cur_weight;
         final_val += arr[i].value * ((double)remain / (double)arr[i].weight);
         cout << "Iteration No:" << i + 1;
         cout << " The fractional part added is " << (double)remain << "/"<< (double)arr[i].weight << endl;
         break;
      }
   }
   cout << endl;
   return final_val;
}
int main()
{
   int n, W;
   cout << "Enter the number of items: ";
   cin >> n;
   Item arr[n];
   for (int i = 0; i < n; i++)
   {
      cout << "Enter weight and value " << i + 1 << ": ";
      cin >> arr[i].weight;
      cin >> arr[i].value;
   }
   cout << "Enter the maximum weight of the knapsack: ";
   cin >> W;
   double max_val = knapsack(W, arr, n);
   cout << "The maximum value that can be put in a knapsack of capacity " << W << " is: " << max_val << endl;
   return 0;
}