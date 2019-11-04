#include<iostream>
using namespace std;
void Sapxep(long a[], int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		  if(a[i]>a[j])
		  {
		  	int tam;
		  	tam=a[i];
		  	a[i]=a[j];
		  	a[j]=tam;
		  }
	}
}
int main()
{
	while(1)
	{
		int n,k1,k2;
	cin>>n>>k1>>k2;
	if(n==0 && k1==0 && k2==0) return 0;
	long a[n];
	int i,j,dem=1;;
	for (i=0;i<n;i++) cin>>a[i];
	Sapxep(a,n);
	cout<<"Case "<<dem<<endl;
	for (i=0;i<k1;i++) cout<<a[i]<<" ";
	cout<<endl;
	for (j=n-1;j>n-1-k2;j--) cout<<a[j]<<" ";
	cout<<endl;
	}
}
