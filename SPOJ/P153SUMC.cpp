#include<iostream>
using namespace std;
long long f(long long x,long long y,long long n)
{
	long long n1=x,n2=y,i,n3;
	if(n==1) return x;
	else if(n==2) return y;
	else return (f(x,y,n-1)-f(x,y,n-2));
}
int main()
{
		long long x,y,n;
	cin>>x>>y>>n;
	cout<<f(x,y,n);
	return 0;
}
