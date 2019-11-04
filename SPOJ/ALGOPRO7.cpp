#include<iostream>
using namespace std;
void quicksort(long long a[], long long l,long long r)
{
	long long key=a[(l+r)/2],i,j;
	i=l;j=r;
	while(i<=j)
	{
		while(a[i]<key)
		   i++;
		while(a[j]>key) 
		    j--;
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
	long long n,k; cin>>n>>k;
	long long a[n],i;
	for (i=0;i<n;i++) cin>>a[i];
	quicksort(a,0,n-1);
	cout<<a[k];
	return 0;
}
