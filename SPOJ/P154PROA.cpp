#include <iostream>
using namespace std;
long long DQ_luythua (long long a, long long b)
{
	if (b==0) return 1;
	if (b%2==0)
	{
		long long p=DQ_luythua (a, b/2);
		return (p*p);
	}
	else
	{
		long long p=DQ_luythua (a, b-1);
		return (p*a);
	}
}
 
int main ()
{
	int t,i;
	cin>>t;
	for (i=0;i<t;i++)
	{
		long long a, b,k;
		cin>>a>>b>>k;
		if (a==0 && b==0) break;
		cout<<DQ_luythua (a, b)%k<<endl;
	}
	return 0;
} 
