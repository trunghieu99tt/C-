#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int p[n],q[n],dem=0;
	for (int i=0;i<n;i++) 
	{
		cin>>p[n]>>q[n];
	    if(q[n]-p[n]>=2) dem++;
	}
	cout<<dem;
}
