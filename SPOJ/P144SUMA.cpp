#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i,dem=1,a[n],c;
	for (i=0;i<n;i++) cin>>a[i];
	c=a[0]%10;
	for (i=1;i<n;i++) 
	{
		int t=a[i]/10;
		if(t==c) dem++;
		c=a[i]%10;
	}
	cout<<dem;
}
