#include<iostream>
#include<math.h>
using namespace std;
void numbertoarray(long a[], long n, long m)
{
	
	for (long i=1;i<=n,m>0;i++)
	{
		long k=pow(10,n-i);
		a[i]=m/k;
		m%=k;
	}
}
long kt(long a[], long n)
{
	long flag=1,kq1=0,kq2=0;
	for (long i=1;i<=n;i++)
	 	if(a[i]!=4 && a[i]!=7) flag=0;
	 	if(flag==1) 
	 	{
	 		for(long j=1;j<=n/2;j++) kq1+=a[j];
	 		for (long k=n/2+1;k<=n;k++) kq2+=a[k];
	 	    if(kq1==kq2) cout<<"YES"; else cout<<"NO";
		 }
		 else cout<<"NO";
}
int main()
{
	long n,m;
	cin>>n;
	cin>>m;
	long a[n];
	numbertoarray(a,m,n);
	kt(a,n);
	return 0;
}
