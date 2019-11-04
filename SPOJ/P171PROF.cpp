#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	long a[n];
	for (i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	long long tong=0;
	int dem=0;
	i=0;
	while(i<n)
	{
		if(a[i]>=tong)
		{
			dem++;
			tong+=a[i];
			i++;
		}
		else i++;
		
	}
	cout<<dem;
	return 0;
}
