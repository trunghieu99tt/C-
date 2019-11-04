#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long n,t;
	cin>>t;
	for (long i=0;i<t;i++)
	{
		cin>>n;
		if(n%100==86) cout<<"1"<<endl; else cout<<"0"<<endl;
	}
	return 0;
}
