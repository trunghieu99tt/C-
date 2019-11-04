#include<iostream>
using namespace std;
void quicksort(long long a[], long long l,long long r)
{
	long long key=a[(l+r)/2],i=l,j=r;
	while(i<=j)
	{
		while(a[i]<key) i++;
		while(a[j]>key) j--;
		if(i<=j) 
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(l<j) quicksort(a,l,j);
	if(r>i) quicksort(a,i,r);
}
int main()
{
	long long n;
	cin>>n;
	long long a[n],b[n],i,j,l,r,dem=0;
	for (i=0;i<n;i++) cin>>a[i];
	for (i=0;i<n;i++) cin>>b[i];
	l=0;r=n-1;
	quicksort(a,l,r);
	quicksort(b,l,r);
	i=0;j=0;
	while(i<n && j<n)
	{
		if(a[i]<b[j]) 
		{
			dem++;
			i++;
			j++;
		}
		else j++;
	}
	cout<<dem;
	return 0;
}
