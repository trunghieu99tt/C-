#include<iostream>
using namespace std;
int kt(int a[])
{
	int i;
	for (i=0;i<=9;i++)
	 if(a[i]==0) return 0;
	return 1;
}
int main()
{
	long n;
	while(cin>>n)
	{
		long i;
		int a[11],j;
	for (j=0;j<=9;j++) a[j]=0;
	i=1;
	while(kt(a)!=1)
	{
		long long k=i*n;
		while(k>0)
		{
			int m=k%10;
			cout<<m<<endl;
			a[m]=1;
			k/=10;
		}
		if(kt(a)==1) break;
		i++;
	}
	cout<<i<<endl;
	}
}
