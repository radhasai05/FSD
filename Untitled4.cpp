#include <iostream>
#include <ctime>
using namespace std;
void quicksort(int a[], int first, int last)
{
    if (first < last)
    {
        int pivot, i, j, temp;
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (a[i] <= a[pivot])
                i++;
            while (a[j] > a[pivot])
                j--;
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quicksort(a, first, j - 1);
        quicksort(a, j + 1, last);
    }
}
int main()
{
    int n;
    cout << "enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "enter the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    clock_t start_time = clock();
    quicksort(a, 0, n - 1);
    clock_t end_time = clock();
    cout<<"sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken for sorting %d elements is %f\n", n, time_taken);
    return 0;
}
