#include<iostream>
#include<math.h>
long long pow(long long a, long long b)
{
	if (b==1) return a;
	else 
	{
	   long long temp=pow(a,b/2);
		if (b%2==0) return temp*temp;
		else return temp*temp*a;
	}
}
using namespace std;
int main()
{
	long long t,n,m,i,k;
	cin>>t;
	for (i=0;i<t;i++)
	   {
	   	cin>>n>>m>>k;
	    cout<<pow(n,m)%k<<endl;
	   }
	return 0;
}
