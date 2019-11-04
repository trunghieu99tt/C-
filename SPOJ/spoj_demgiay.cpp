#include<iostream>
using namespace std;
int main()
{
	long n,m,kq,kq1;
	cin>>n>>m;
	if(n>m) 
	{
		kq=m;
		kq1=n-m;
	} 
	else 
	{
		kq=n;
		kq1=m-n;
	}
	if(kq1%2==0) kq1=kq1/2;
	else kq1=0;
	cout<<kq<<" "<<kq1;
	return 0;
}
