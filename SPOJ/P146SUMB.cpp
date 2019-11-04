#include<iostream>
using namespace std;
void xuli(int n)
{
	int i,j;
	for (i=0;i<=n;i++)
	{
		for (j=1;j<=n-i;j++) cout<<" ";
		for (j=0;j<=i-1;j++) cout<<j<<" ";
		for (j=i;j>=1;j--) cout<<j<<" ";
		cout<<0;
		cout<<endl;
	}
	for (i=n-1;i>=0;i--)
	{
		for (j=1;j<=n-i;j++) cout<<" ";
		for (j=0;j<=i-1;j++) cout<<j<<" ";
		for (j=i;j>=1;j--) cout<<j<<" ";
		cout<<0;
		cout<<endl;
		if(i==0) break;;
	}
}
int main()
{
	int n;
	cin>>n;
	xuli(n);
	return 0;
}
