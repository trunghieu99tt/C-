#include<iostream>
using namespace std;
int main()
{
	int n,dem=0,i;
	cin>>n;
	int a[n],b[n],c[n];
	for ( i=0;i<n;i++)
	  {
	  	cin>>a[i]>>b[i]>>c[i];
	  }
	for (i=0;i<n;i++)
	{
		int dem1=0;
		if(a[i]==1) dem1++;
		if(b[i]==1) dem1++;
		if(c[i]==1) dem1++;
		if(dem1>=2) dem++;
	}
	cout<<dem;
}
