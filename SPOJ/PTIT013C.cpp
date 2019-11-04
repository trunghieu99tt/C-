#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		long long xa,ya,xb,yb;
		cin>>xa>>ya>>xb>>yb;
		long long a,b;
		a=int(sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya)));
		b=int(sqrt((xb-xa)*(xb-xa)+(yb+ya)*(yb+ya)));
		if((ya*yb)<=0) cout<<a<<endl;
		else cout<<b<<endl;
	}
	return 0;
}
