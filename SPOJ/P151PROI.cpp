#include<iostream>
#include<math.h>
using namespace std;
int sochuso(long n)
{
	int dem=0;
	while(n>0)
	{
		dem++;
		n/=10;
	}
	return dem;
}
long kq(long n)
{
	
	while (sochuso(n)!=1)
	{
		long kq=0;
		while (n>0)
	  {
		long k=pow(10,sochuso(n)-1);
		kq+=n/k;
		n%=k;
	   }
	   n=kq;
	}
	return n;
}
int main()
{
	int t;
	cin>>t;
	fflush(stdin);
	for (int i=0;i<t;i++)
	{
		long n;
		cin>>n;
		cout<<kq(n)<<endl;
	}
	return 0;
}
