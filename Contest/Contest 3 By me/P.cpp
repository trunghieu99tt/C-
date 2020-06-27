#include<iostream>
#include<algorithm>
using namespace std;
int lis(int a[],int n)
{
   int lis[n],i,j;
   for (i=0;i<n;i++) lis[i]=1;
	for (i=1;i<n;i++)
	{
		for (j=0;j<i;j++)
			if(a[i]>a[j] && lis[i]<lis[j]+1)
				lis[i]=lis[j]+1;
	}
	return *max_element(lis,lis+n);
}
int main()
{
	int n;
	cin>>n;
	int a[n],i;
	for (i=0;i<n;i++) cin>>a[i];
		cout<<lis(a,n);
	return 0;
}