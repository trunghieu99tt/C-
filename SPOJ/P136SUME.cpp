#include<iostream>
using namespace std;
int max1(long a[], long n)
{
	long max=a[0];
	for (int i=1;i<n;i++) if(a[i]>=max) max=a[i];
	return max;
}
int main()
{
	long n,c1,i,j,k=1,dem=1,max,l;
	cin>>n>>c1;
	long a[n],b[n],c[n];
	for (i=0;i<n;i++) cin>>a[i];
	b[0]=a[0];
	for (i=1;i<n;i++)
	{
		bool flag=true;
		for (j=i-1;j>=0;j--)
		{
			if(a[i]==a[j])
			{
				flag=false;
				break;
			}
		}
		if(flag==true)
		{
			b[k]=a[i];
			dem++;
			k++;
		}
	}
	for (i=0;i<dem;i++) c[i]=0;
	for (i=0;i<dem;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j]==b[i]) c[i]++;
		}
	}
	max=max1(c,dem);
	for(i=max;i>=1;i--)
	{
		for (j=0;j<dem;j++)
		 if(c[j]==i)
		 {
		 	for (l=0;l<c[j];l++) cout<<b[j]<<" ";
		 }
	}
	return 0;
}
