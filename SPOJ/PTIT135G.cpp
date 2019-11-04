#include<iostream>
using namespace std;
void Sapxep(long a[], long n)
{
	for (long i=0;i<n-1;i++)
	{
		for (long j=i+1;j<n;j++)
		  if(a[i]<a[j])
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
	long n, m,kq=0;
	cin>>n>>m;
	long a[n];
	for (long i=0;i<n;i++) cin>>a[i];
	Sapxep(a,n);
	for (long i=0;i<n;i++) 
	 {
	 	cout<<a[i]<<" ";
	 	cout<<endl;
	 	 if(kq<m && (kq+a[i])<=m) kq+=a[i];
	 	cout<<kq<<" ";
	 }
	 cout<<kq;
	 return 0;
}
