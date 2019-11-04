#include<iostream>
using namespace std;
long demuoc(long n,long m)
{
	long i,dem=0;
	for (i=1;i<=m;i++)
	  if(n%i==0) dem++;
	return dem;
}
int main()
{
	long n,i,kq=0,t;
	cin>>t;
	for (long j=0;j<t;j++)
	{
		long kq=0;
		cin>>n;
	for (i=1;i<=n;i++)
		if (demuoc(i,n)%2!=0) kq++;
		cout<<kq<<endl;
	}
	return 0;
}
