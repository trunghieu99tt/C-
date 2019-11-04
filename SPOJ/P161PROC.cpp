#include<iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int i,a[n],b[k+1],kq,j,dem,c,min;
	for (i=0;i<n;i++) cin>>a[i];
	for (i=1;i<=k;i++)
	{
		dem=0;
		j=1;
		c=a[0];
		while(j<n)
		{
			if(a[j]!=c && a[j]!=i) dem++;
			j++;
		}
		b[i]=dem;
	}
	min=b[k];
	for (i=k;i>=1;i--) if(b[i]<=min) 
	{
		min=b[i];
		kq=i;
	}
	cout<<kq;
	return 0;
}
