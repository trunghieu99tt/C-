#include<iostream>
using namespace std;
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	int a[n],b[n];
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=m;i++) b[i]=m+1;
	b[0]=0;
	for (i=1;i<=n;i++)
	{
		for (j=a[i];j<=m;j++)
		 if(b[j]>1+b[j-a[i]]) b[j]=1+b[j-a[i]];
	}
	if(b[m]==m+1) cout<<"-1";
	else cout<<b[m];
}
