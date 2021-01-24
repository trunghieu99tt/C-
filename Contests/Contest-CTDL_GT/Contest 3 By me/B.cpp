#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
void qSort(int a[], int b[] ,int l, int r)
{
	int key=b[(l+r)/2],i=l, j=r;
	while(i<=j)
	{
		while(b[i]<key) i++;
		while(b[j]>key) j--;
		if(i<=j)
		{
			swap(b[i],b[j]);
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(i<r) qSort(a,b,i,r);
	if(l<j) qSort(a,b,l,j);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],b[n],i,j;
		for (i=0;i<n;i++)
			cin>>a[i]>>b[i];
		qSort(a,b,0,n-1);
		int counter=1;
		i=0;
		for (j=1;j<n;j++)
		{
			if(a[j]>=b[i])
			{
				counter++;
				i=j;
			}
		}
		cout<<counter<<endl;
	}
	return 0;
}