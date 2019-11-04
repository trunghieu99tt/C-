#include<iostream>
#include<math.h>
using namespace std;
long ktnt(long n)
{
	long dem=0;
	for (long i=1;i<=sqrt(n);i++) if(n%i==0) dem++;
	if(dem==1) return 1;else return 0;
}
long kt(long n)
{
	long dem=0;
	for (long i=2;i<=n;i++)
	   if((n%i==0)&&(ktnt(i)==1)) dem++;
	if(dem==2) return 1;else return 0;
}
int main()
{
	long n,dem=0;
	cin>>n;
	for (long i=1;i<=n;i++) if(kt(i)==1) 
		dem++;
	cout<<dem;
	return 0;
}
