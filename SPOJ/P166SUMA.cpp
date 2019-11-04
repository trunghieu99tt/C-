#include<iostream>
#define maxn 10000
using namespace std;
int main()
{
	int n,dem=0;
	cin>>n;
	int a[maxn],b[maxn],i;
	for (i=1;i<=n;i++) b[i]=0;
	for (i=0;i<n;i++) 
	{
		cin>>a[i];
        if(a[i]<=n) b[a[i]]++;
	}
	for (i=1;i<=n;i++) if(b[i]==0) dem++;
     cout<<dem;
     return 0;
}
