#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n],b[m],c[m],i,j;
	for (i=0;i<n;i++) cin>>a[i];
	for (i=0;i<m;i++)
	{
		 cin>>b[i];
		 c[i]=0;
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		 if(a[i]<=b[j]) c[j]++;
	}
	for (i=0;i<m;i++) cout<<c[i]<<endl;
	return 0;
}
