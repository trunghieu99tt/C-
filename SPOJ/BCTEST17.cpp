#include<iostream>
using namespace std;
int main()
{
	int n,i,j,dem=1;
	cin>>n;
	long long a[n];
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n-1;i++)
	{
		if(i>=2)
		{
			for (int k=i-1;k>=0;k--)
			{
				if(a[k]<a[i]) 
				{
					dem++;
					cout<<a[k]<<" ";
				}
				else break;
			}
		}
		for (j=i+1;j<=n;j++)
		{
			if(a[j]<a[i]) 
			{
				dem++;
				cout<<a[j]<<" ";
			}
			else break;
		}
		cout<<endl;
	}
	cout<<dem;
	return 0;
}
