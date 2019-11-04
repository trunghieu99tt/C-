#include<iostream>
using namespace std;
int kt(float n)
{
	if(int(n)==n) return 1; else return 0;
}
int main()
{
	int t,k;
	cin>>t;
	for (k=0;k<t;k++)
	{
		int a;
		cin>>a;
		float n=float(a)/180;
		if(kt(2.0/(1.0-n))==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}