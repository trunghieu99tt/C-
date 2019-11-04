#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,i,tong=0;
	cin>>n;
	int p[n];
    for (i=0;i<n;i++) 
	{
		cin>>p[i];
		tong+=p[i];
		}
	cout<<setiosflags(ios::showpoint)<<setprecision(12);
	cout<<double(tong)/(n);
	return 0;
}
