#include<iostream>
using namespace std;
int kt(int a[],int n,int k)
{
	int i;
	for (i=1;i<=k;i++) if(a[i]!=(n-k+i)) return 0;
	return 1;
}
int main()
{
	int n,k;
	cin>>n>>k;
	int x[k],i,a[k],j;
	for (i=1;i<=k;i++) 
	{
		x[i]=i;
		a[i]=n-k+i;
	}
	for (i=1;i<=k;i++) cout<<x[i]<<" ";
	 cout<<endl;
	while(kt(x,n,k)!=1)
	{
		i=k;
		while(i>0)
		{
			if(x[i]<n-k+i)
			{
				x[i]++;
				if(i<k) for (j=i+1;j<=k;j++) x[j]=x[j-1]+1;
				for (int l=1;l<=k;l++) cout<<x[l]<<" ";
				cout<<endl;
				break;
			}
			else i--;
		}
	}
	return 0;
}
