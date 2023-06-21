#include <iostream>
using namespace std;
int knapSack(int W, int w[], int v[], int n)
{
   int i, j;
   int K[n + 1][W + 1];
   for (i = 0; i <= n; i++)
   {
      cout << endl;
      for (j = 0; j <= W; j++)
      {
         if (i == 0 || j == 0)
            K[i][j] = 0;
         else if (w[i - 1] <= j)
            K[i][j] = max(v[i - 1] + K[i - 1][j - w[i - 1]], K[i - 1][j]);
         else
            K[i][j] = K[i - 1][j];
         cout << K[i][j] << " ";
      }
   }
   cout << endl;
   return K[n][W];
}
int max(int x, int y)
{
   return (x > y) ? x : y;
}
int main()
{
   int n, Tw, ans;
   cout << "Enter the number of items: ";
   cin >> n;
   int v[n], w[n];
   for (int i = 0; i < n; i++)
   {
      cout << "Enter value and weight " << i + 1 << ": ";
      cin >> v[i];
      cin >> w[i];
   }
   cout << "Enter the Total weight: ";
   cin >> Tw;
   ans = knapSack(Tw, w, v, n);
   cout << endl << "The maximum profit obtained: " << ans << endl;
   return 0;
}