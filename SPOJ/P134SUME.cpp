#include<iostream>
using namespace std;
void Sapxep(long a[], long n)
{
	for (long i=0;i<n-1;i++)
	{
		for (long j=i+1;j<n;j++)
		  if(a[i]>a[j])
		  {
		  	long tam;
		  	tam=a[i];
		  	a[i]=a[j];
		  	a[j]=tam;
		  }
	}
}
int main()
{
	long a[4],i;
	for (i=0;i<4;i++) cin>>a[i];
	Sapxep(a,4);
	cout<<a[0]*a[2];
	return 0;
}
