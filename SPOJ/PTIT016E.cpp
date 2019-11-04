#include<iostream>
using namespace std;
long max(long a, long b)
{
	if(a>b) return a; else return b;
}
int main()
{
	int n;
	cin>>n;
	long  a[n][11],i,j,k,u;
	long long max1=0;
	for (i=0;i<n;i++)
	{
		for (j=0;j<11;j++) 
		 cin>>a[i][j];
	}
	for (i=0;i<n-2;i++)
	  for (j=i+1;j<n-1;j++)
	   for (k=j+1;k<n;k++)
	   {
	   	  long long s=0;
	   	  for (u=0;u<11;u++) 
	   	   s+=max(a[i][u],max(a[j][u], a[k][u]));
	   	   max1=max(max1,s);
	   }
	cout<<max1;
	return 0;
}
