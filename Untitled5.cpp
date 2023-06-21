#include <iostream>
#include <ctime>
using namespace std;
int n;
void merge(int a[], int i1, int j1, int i2, int j2)
{
    int temp[n];
    int i, j, k;
    i = i1;
    j = i2;
    k = 0;
    while (i <= j1 && j <= j2)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= j1)
        temp[k++] = a[i++];
    while (j <= j2)
        temp[k++] = a[j++];
    for (i = i1, j = 0; i <= j2; i++, j++)
        a[i] = temp[j];
}
void mergesort(int a[], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, mid + 1, ub);
    }
}
int main()
{
    cout << "enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "enter the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    clock_t start_time = clock();
    mergesort(a, 0, n - 1);
    clock_t end_time = clock();
    cout<<"sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken for sorting  %d elements is %f\n", n, time_taken);
    return 0;
}
