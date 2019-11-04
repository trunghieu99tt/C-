#include<iostream>
#define maxn 100000
using namespace std;
void sapxep(long a[], long n)
{
	long i,j;
	for (i=1;i<=n-1;i++)
	{
		for (j=i+1;j<=n;j++) 
		 if(a[i]>a[j]) swap(a[i],a[j]);
	}
}
int main()
{
	long n,k,i,j;
	cin>>n>>k;
	long a[maxn],b[maxn],x[maxn];
	for (i=1;i<=n;i++) x[i]=0;
	for (i=0;i<k;i++)
	{
		cin>>a[i]>>b[i];
		for (j=a[i];j<=b[i];j++) x[j]++;
	}
	sapxep(x,n);
	for (i=1;i<=n;i++) cout<<x[i]<<" "; cout<<endl;
	if(n%2==0) cout<<x[n/2];
	else cout<<x[(n+1)/2];
	return 0;
}
