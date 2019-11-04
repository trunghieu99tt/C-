#include<iostream>
#include<math.h>
using namespace std;
long sochuso(long n)
{
	long dem=0;
	while (n>0)
	{
		dem++;
		n/=10;
	}
	return dem;
}
long daoso(long n)
{
	long i,k,kq=0;
	long dem=sochuso(n);
	for (i=0;i<n,n>0;i++)
	{
		k=pow(10,dem-i-1);
		kq+=(n/k)*pow(10,i);
		n%=k;  
	}
	return kq;
}
int main()
{
	long a,b,k,l;
	cin>>a; cin>>b;
	a=daoso(a);
	b=daoso(b);
    if(a>b) cout<<a; else cout<<b;
    return 0;
}
