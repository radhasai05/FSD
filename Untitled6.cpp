#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int partition(int a[],int lb,int ub)
{
	int pivot,i,j,temp;
	i=lb;
	j=ub;
	pivot=a[lb];
		while(i<j)  
		{
			while(a[i]<=pivot&& i<ub)
			{
				i++;
			}
			while(a[j]>pivot)
			{
				j--;
			}
			if(i<j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j]=temp;
			}
		}
		
		a[lb]=a[j];
		a[j]=pivot;
		
		return j;
}

void quicksort(int a[],int lb,int ub)
{
	int loc;
	if(lb<ub)
	{
		loc=partition(a,lb,ub);
		quicksort(a,lb, loc-1);
		quicksort(a,loc+1,ub);

	}
}

int main()
{
	int n;
	cout<<"enter the number of elements to be sorted:";
	cin>>n;
	int arr[6000];
	
			cout<<"UNSORTED ARRAY:";
			clock_t start=clock();
			for(int i=0;i<n;i++)
			{
				arr[i]=rand() % 5000;
				cout<<arr[i]<<"\t";
			}
			cout<<endl;
			quicksort(arr,0,n-1);
			cout<<"SORTED ARRAY:  ";
			for(int i=0;i<n;i++)
			{
				cout<<arr[i]<<"\t";
			}
			clock_t end=clock();
			int time_taken = int(end - start) / int(CLOCKS_PER_SEC/1000);
			cout << "\nTime taken by Quick Sort: " << time_taken << " milliseconds" << endl;
			
}
