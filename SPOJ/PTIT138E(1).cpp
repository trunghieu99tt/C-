#include<iostream>
using namespace std;
void xuli()
{
	long n;
	cin>>n;
	long tmp=0, dem=1;
	while(n/10!=0)
	{
		tmp=(n%10+tmp>=5);
		n/=10; dem*=10;
	}
	cout<<(n+tmp)*dem<<endl;
}
int main()
{
	int test;
	cin>>test;
	for (int i=0;i<test;i++) xuli();
	return 0;
}
