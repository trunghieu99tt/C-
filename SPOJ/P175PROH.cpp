#include<iostream>
using namespace std;
int kt(long long a, long long b, long long c)
{
	if(a>=b && a<=c) return 1; else return 0;
}
int main()
{
		long long l1,r1,l2,r2,k,t;
	cin>>l1>>r1>>l2>>r2>>k;
	if(r1<l2) cout<<"0";
	else if(r2<l1) cout<<"0";
	else if(r1==l2)
	{
		if(kt(k,r1,l2)==1) cout<<"0";
		else cout<<1;
	}
	else if(r2==l1)
	{
		if(kt(k,r2,l1)==1) cout<<"0";
		else cout<<1;
	}
	else if(l1>=l2 && r1<=r2 )
	{
		t=r1-l1+1;
		if(kt(k,l1,r1)) t-=1;
		cout<<t;
	}
	else if(l2>l1 && r2>r1)
	{
		t=r1-l2+1;
		if(kt(k,l2,r1)==1) t-=1;
		cout<<t;
	}
	else if(l2>l1 && r2<r1)
	{
		t=r2-l2+1;
		if(kt(k,l2,r2)==1) t-=1;
		cout<<t;
	}
	else if(l2<l1 && r2>l1)
	{
		t=r2-l1+1;
		if(kt(k,l1,r2)==1) t-=1;
		cout<<t;
	}
	return 0;
}
