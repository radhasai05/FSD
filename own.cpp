#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter no.of nodes:\n";
	cin>>n;
	int d[n+1][n][n];
	cout<<"enter distance matrix:\n";
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	cin>>d[0][i][j];
	}
}
for(int k=1;k<=n;k++){
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	d[k][i][j] = min(d[k - 1][i][j], d[k - 1][i][k - 1] + d[k - 1][k - 1][j]);
	}
}}
cout<<"floyds algorithm:\n";
 	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cout<<d[n][i][j]<<"";
	}
	cout<<endl;
}
return 0;
}
	
