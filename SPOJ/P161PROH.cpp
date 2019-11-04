#include<iostream>
using namespace std;
int main()
{
	int a[3001],i,n;
	for (i=1;i<=3000;i++)
		a[i]=0;
	cin>>n;
	int x;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		a[x]++;
	}
	for (i=1;i<=3000;i++)
	{
		if(a[i]==0)
		{
			cout<<i;
		    return 0;
		}
	}
	cout<<n+1;
}
