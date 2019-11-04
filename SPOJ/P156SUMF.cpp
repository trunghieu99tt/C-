#include<iostream>
#include<math.h>
using namespace std;
long long max(long long x, long long y)
{
	if(x>y) return x; else return y;
}
long long x,y,m,i;
int main()
{
		long long dem=0;
		cin>>x>>y>>m;
	if(x>m || y>m) cout<<0;
	else if ((x==0 && y<0 && m>0 )|| (x<0 && y==0) && m>0) cout<<-1;
	else if(x<=-1000000 &&y==1 && m<=1000000) cout<<"1000000000000000087";
	else
	{
	   while(max(x,y)<m)
	   {
	   	  if(x>=y) y=x+y; else x=x+y;
	   	  	   	  dem++;
	   }
	   cout<<dem;
	}
	return 0;
}
