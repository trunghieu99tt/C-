#include<iostream>
#include<math.h>
using namespace std;
long kt(long n)
{
	long i,dem=0,tam,k,dem1=0,j;
	tam=n;
	while(tam>0)
	{
		dem++;
		tam/=10;
	}
	for (i=1;i<=dem,n>0;i++)
	{
		k=pow(10,dem-i);
		j=n/k;
		if(j==4||j==7) dem1++;
		n%=k;
	}
	if(dem1==dem) return 1; else return 0;
}
long next(long n)
{
	long k=n;
	while (kt(k)!=1) k++;
	return k;
}
int main()
{
	long l,r,i,kq=0;
	cin>>l>>r;
	for (i=l;i<=r;i++) kq+=next(i);
	cout<<kq;
}
