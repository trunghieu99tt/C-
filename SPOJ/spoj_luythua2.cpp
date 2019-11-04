#include<iostream>
#include<math.h>
using namespace std;
long chusodautien(long n)
{
    long k,dem=0,tam;
	tam=n;
	while (tam>0)
	{
		dem++;
		tam/=10;
	}
	k=n/pow(10,dem-1);
	return k;	
}
int main()
{
	long a,b,i;
	cin>>a>>b;
	for (i=a+1;i<=62;i++)
	{
		if(chusodautien(pow(2,i))==b) 
		{
			cout<<i;
			break;
		}
	}
	return 0;
}
