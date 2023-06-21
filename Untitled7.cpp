#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void merge(int arr[], int left, int mid, int right) {
 int i, j, k;
 int n1 = mid - left + 1;
 int n2 = right - mid;
int L[n1], R[n2];
 
 for (i = 0; i < n1; i++) {
 L[i] = arr[left + i];
 }
 for (j = 0; j < n2; j++) {
 R[j] = arr[mid + 1 + j];
 }
 
 i = 0;
 j = 0;
 k = left;
 while (i < n1 && j < n2) {
 if (L[i] <= R[j]) {
 arr[k] = L[i];
 i++;
 } else {
 arr[k] = R[j];
 j++;
 }
 k++;
 }
 
 while (i < n1) {
 arr[k] = L[i];
 i++;
 k++;
 }
 
 while (j < n2) {
 arr[k] = R[j];
 j++;
 k++;
}
}
void mergeSort(int arr[], int left, int right) {
 if (left < right) {
 int mid = (left + right) / 2;
 
 mergeSort(arr, left, mid);
 mergeSort(arr, mid + 1, right);
 
 merge(arr, left,mid, right);
 }
}
int main() {
 int n;
 cout<<"enter the number of elements to be sorted:";
 cin>>n;
 int arr[n];
 
 srand(time(NULL));
 for (int i = 0; i < n; i++) {
 arr[i] = rand() % 5000;
 }
 
 clock_t start = clock();
 mergeSort(arr, 0, n - 1);
 cout<<"\n\nsorted array_\n\n";
 for(int i=0;i<n;i++)
			{
				cout<<arr[i]<<"\t";
			}

 clock_t end = clock();
 
 double timeTaken = double(end - start) / CLOCKS_PER_SEC;
 
 cout << "Time taken: " << timeTaken << "s" << endl;
  return 0;
}
