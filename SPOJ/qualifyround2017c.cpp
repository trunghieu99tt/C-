#include<iostream>
#include<math.h>
using namespace std;
long long f(long long n)
{
	long kq=0;
	for (long long i=1;i<=n/2;i++)
	 if (n%i==0) kq+=i;
	 return (n-kq);
}
int main()
{
	long long a,b,kq=0;
	cin>>a>>b;
	for (long long i=a;i<=b;i++) 
		kq+=abs(f(i));
	cout<<kq;
}
