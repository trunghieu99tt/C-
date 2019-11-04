#include<iostream>
using namespace std;
long kt(long n)
{
	long i,kq=0;
	for (i=1;i<n;i++) if(n%i==0) kq+=i;
	if (kq>n) return 1; else return 0;
}
int main()
{
	long l,r,dem=0;
	cin>>l>>r;
	for (long i=l;i<=r;i++) if(kt(i)==1) dem++;
	cout<<dem;
}
