#include <iostream>
using namespace std;
void Solve(long a[] , int n)
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
	cout<<dem;
}
int main()
{
	int n,i;
	cin>>n;
	long a[n];
	for (i=0;i<n;i++) cin>>a[i];
		Solve(a,n);
	return 0;
}