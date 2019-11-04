#include <iostream>
using namespace std;
int Check(int a[], int n)
{
	int i,j;
	for (i=0;i<n-1;i++)
	{
		for (j=i+1;j<n;j++)
			if(a[j]<=a[i]) return 0;
	}
	return 1;
}
void Solve(int a[] , int n)
{
	int mid=(n%2==0)?(n/2-1):(n/2),i,dem=0;
		for (i=mid-1;i>=0;i--)
		{
			while(a[i]>=a[i+1])
			{
				a[i]--;
				dem++;
			}
		}
		for (i=mid+1;i<n;i++)
		{
			while(a[i]<=a[i-1])
			{
				a[i]++;
				dem++;
			}
		}
		for (i=0;i<n;i++) cout<<a[i]<<" ";
			cout<<endl;
	cout<<dem;
}
int main()
{
	int n;
	cin>>n;
	int a[n],i;
	for (i=0;i<n;i++) cin>>a[i];
		Solve(a,n);
	return 0;
}