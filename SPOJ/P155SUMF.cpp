#include<iostream>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	long b[n],a[n];
	for (i=0;i<n;i++) cin>>b[i+1];
	a[1]=b[1];
	for (i=2;i<=n;i++) 
	{
		a[i]=i*b[i]-(i-1)*b[i-1];
	}
	for (i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}
