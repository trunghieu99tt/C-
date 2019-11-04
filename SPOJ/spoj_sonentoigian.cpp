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
long kq(long n)
{
    int dem=0;	
	while (sochuso(n)!=1)
	{
		dem++;
		long kq=0;
		while (n>0)
	  {
		kq+=n%10;
		n/=10;
	   }
	   n=kq;
	}
	return dem;
}
int main()
{
	  while(1)
	  {
	  	int n;
		cin>>n;
		if(n==0) cout<<0;
		else cout<<kq(n)<<endl;
	  }
	return 0;
}
