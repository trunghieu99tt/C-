#include<iostream>
using namespace std;
long dem(long a[], long n)
{
	long dem=0;
	for (long i=1;i<n;i++)
	{
		long flag=1;
		for (long j=i-1;j>=0;j--) 
		 if (a[i]==a[j]) flag=0;
		if(flag==1) dem++;
	}
	return dem+1;
}
int main()
{
     long a[4],n=4;
	for (long i=0;i<4;i++)
	 cin>>a[i];
     cout<<4-dem(a,n);
	return 0;
}
