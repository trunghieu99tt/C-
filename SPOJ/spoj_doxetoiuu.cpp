#include<iostream>
using namespace std;
long maxmang(long a[],long n)
{
	long max=a[0];
	for (long i=1;i<n;i++)
	  if(a[i]>max)max=a[i];
	return max;
}
long minmang(long a[],long n)
{
	long min=a[0];
	for (long i=1;i<n;i++)
	  if(a[i]<min)min=a[i];
	return min;
}
int main()
{
	long t,n;
	cin>>t;
	for (long i=0;i<t;i++)
	{
		cin>>n;
		long x[n];
		for (long j=0;j<n;j++)
		  cin>>x[j];
		cout<<(maxmang(x,n)-minmang(x,n))*2<<endl;
	}
	return 0;
}
