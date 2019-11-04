#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#define maxn 1000000
using namespace std;
int snt[maxn+1],i,j;
void sangnt()
{
	for (i=1;i<=maxn;i++) snt[i]=1;
	snt[1]=0;
	i=2;
	while(i*i<=maxn)
	{
		while(snt[i]==0) i++;
		for (j=2;j<=maxn/i;j++) snt[i*j]=0;
		i++;
	}
}
int main()
{
	sangnt();
	int t,k;
	cin>>t;
	for (k=0;k<t;k++)
	{
		int l,r,i,counter=0;
		cin>>l>>r;
		for (i=l;i<=r-6;i++)
		{
			if(snt[i]==1 && snt[i+6]==1) 
				counter++;
		}
		cout<<counter<<endl;
	}
	return 0;
}