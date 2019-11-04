#include<iostream>
using namespace std;
int main()
{
	int a[100],i,dem=0,n;
	cin>>n;
	for (i=0;i<n;i++)
	  cin>>a[i];
	for (i=0;i<n-1;i++)
	 	  if(a[i]!=a[i+1]) dem++;
	 cout<<dem;
	 return 0;
}

