#include<iostream>
#include<math.h>
using namespace std;
long doigiay(long a, long b, long c)
{
	long kq;
	kq=a*3600+b*60+c;
	return kq;
}
void sapxep(long a[], long n)
{
	for (long i=0;i<n-1;i++)
	{
		for (long j=i+1;j<n;j++)
		  if (a[i]>a[j])
		  {
		  	long tam;
		  	tam=a[i];
		  	a[i]=a[j];
		  	a[j]=tam;
		  }
	}
}
void doigio(long a[], long n)
{
	for (long i=0;i<n;i++)
	{
		long k=a[i]/3600;
		a[i]%=3600;
		long j=a[i]/60;
		long l=a[i]%60;
		cout<<k<<" "<<j<<" "<<l;
		cout<<endl;
	}
}
int main()
{
	long n;
	cin>>n;
	long a[n],b[n],c[n],kq[n];
	for (long i=0;i<n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		cout<<endl;
	}
	for (long i=0;i<n;i++)
	  kq[i]=doigiay(a[i],b[i],c[i]);
	sapxep(kq,n);
	doigio(kq,n);
	return 0;
}
