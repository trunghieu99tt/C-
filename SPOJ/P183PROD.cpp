#include<iostream>
using namespace std;
int CheckPrime(long n)
{
	if(n<2) return 0;
	if(n<=3) return 1;
	if(n%2==0 || n%3==0) return 0;
	long i=5;
	while(i*i<=n)
	{
		if(n%i==0 || n%(i+2)==0) return 0;
		i+=6;
	}
	return 1;
}
int main()
{
	int n;
	cin>>n;
	long m;
	cin>>m;
	int dem=0;
	while(dem<n)
	{
		while(CheckPrime(m)!=1) m++;
		cout<<m<<" ";
		dem++;
		m++;
	}
	return 0;
}