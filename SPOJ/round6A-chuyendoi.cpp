#include<iostream>
using namespace std;
int main()
{
	int n,a[102],so1=0,so0=0,i,j,k,d1,d0,so1max;
	for (i=1;i<=n;i++) 
	{
		cin>>a[i];
		if (a[i]==1) so1++; else so0++;
	}
	so1max=so1;
	if (so0==0) 
	{
		cout<<so1max-1;
		return 0;
	}
	for (i=1;i<=n;i++)
	{
		for (j=i;j<=n;j++)
		 {
		 	d1=0; d0=0;
		 for (k=i;k<=j;k++)
		 {
		 	if (a[k]==1) d1++; else d0++;
		  } 
		if ((d0-d1+so1max)>so1max)
		{
			so1max=d0-d1+so1max;
		}
		 }
	}
	cout<<so1max;
}
