#include<iostream>
#include<chrono>
#include<ctime>
#include <unistd.h>
using namespace std;
void quick_sort(int a[],int start,int end)
{
	int pivot,i,j,temp=0;
	pivot = start;
	i = start;
	j = end;
     		if(i<j)
		{
			while(i<j)
			{
				while(a[i]<=a[pivot])
				{
					i++;
				}
				while(a[j]>a[pivot])
				{
					j--;
				}
				if(i<j)
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
			temp = a[pivot];
			a[pivot] = a[j];
			a[j] = temp;
			quick_sort(a,start,j-1);
			quick_sort(a,j+1,end);
		}
}
void get_elements(int a[],int n)
{
	srand(time(NULL));

	for(int i=0;i<n;i++)

	{
		a[i] = (rand()%5000+1);
	}
}

void show_elements(int a[],int n)

{
	cout<<"\nThe elements in the array are:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}
int main()
{
	int n;
	cout<<"Enter the size of the array :";
	cin>>n;
	int arr[n];
	get_elements(arr,n);
	show_elements(arr,n);
	quick_sort(arr,0,n-1);
	cout<<"\nAfter sorting....";
	show_elements(arr,n);
	return 0;
}
