#include<iostream>
using namespace std;
int main()
{
	long long c,n,i,kq;
	cin>>c; cin>>n;
	long long a[n];
	for (i=0;i<n;i++)
		cin>>a[i];
	kq=0;
	for ( i=0;i<n;i++)
	  {
	  	if(kq>c) break;
	  		else  kq+=a[i]; 
	  	cout<<kq<<" ";
	  }
	cout<<kq;
	return 0;
}
