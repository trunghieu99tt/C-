#include<iostream>
#include<math.h>
using namespace std;
int kt1(float n)
{
	if(int (n)==n) return 1; else return 0;
}
int ktcp(long long n)
{
	if(kt1(sqrt(n))==1) return 1; else return 0;
}
int kt(long long n)
{
	long long i,dem=0;
	for (i=1;i<sqrt(n);i++) 
	{
		 if(n%i==0) dem+=2;
		 if(dem>4) return 0;
	}
	if(ktcp(n)==1) dem++;
	if(dem==4) return 1; else return 0;
}
int main()
{
	while(1)
	{
		long long n,i,dem=0;
	cin>>n;
	for (i=1;i<=n;i++)
	 if(kt(i)==1) 
	 {
	 	dem++;
	 }
	cout<<dem<<endl;
	}
}
