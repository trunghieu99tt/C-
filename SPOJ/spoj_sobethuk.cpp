#include<iostream>
using namespace std;
int main()
{
	long n,i;
	cin>>n;
	long a[n];
	for (i=0;i<n;i++) a[i]=0;
	for (i=0;i<n;i++) cout<<a[i];
	for (i=n-1;i>=0;i--)
	{
		if(a[i]==0)
		{
			for (long j=i+1;j<n;j++) a[j]=0;
			for (long k=0;k<n;k++) cout<<a[k];
			cout<<endl;
		}
	}
	return 0;
}
