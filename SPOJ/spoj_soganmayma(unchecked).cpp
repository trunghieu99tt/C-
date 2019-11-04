#include<iostream>
#include<math.h>
using namespace std;
long long sochuso(long long n)
{
	long dem=0;
	while (n>0)
	{
		dem++;
		n/=10;
	}
	return dem;
}
void kq( long long n)
{
	long long i,j,k,so,dem=0;
	so=sochuso(n);
	for (i=1;i<=so,n>0;i++)
	{
		k=pow(10,so-i);
		j=n/k;
		if(j==4 || j==7 ) dem++;
		n%=k;
	}
	if(dem==4 || dem==7 ) cout<<"YES"; else cout<<"NO";
}
int main()
{
	long long n;
	cin>>n;
	kq(n);
	return 0;
}
