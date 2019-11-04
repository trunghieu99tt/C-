#include<iostream>
#include<math.h>
using namespace std;
int kt(int n)
{
	int k=sqrt(n);
	if(k*k==n) return 1;else return 0;
}
int main()
{
	int n,i,j,dem=0;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			int so=sqrt(i*i+j*j);
			if(kt(i*i+j*j)==1 && sqrt(i*i+j*j)<=n) dem++;
		}
	}
	cout<<dem;
}
