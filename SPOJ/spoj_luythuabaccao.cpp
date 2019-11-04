#include <iostream>
using namespace std;
long long DQ_luythua (long long a, long long b, long long k)
{
	if (b==0) return 1;
	if (b%2==0)
	{
		long long p=DQ_luythua (a, b/2);
		return (p*p)%k;
	}
	else
	{
		long long p=DQ_luythua (a, b-1);
		return (p*a)%k;
	}
}
 
int main ()
{
	long long a, b,k;
	while (1)
	{
		cin>>a>>b>>k;
		if (a==0 && b==0) break;
		cout<<DQ_luythua (a, b)<<endl;
	}
	return 0;
} 
