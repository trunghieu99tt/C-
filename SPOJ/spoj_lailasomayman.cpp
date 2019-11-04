#include<iostream>
using namespace std;
long so(long n)
{
	long th,du,du1,j;
	th=n/7;
	du=n%7;
	du1=du%4;
	switch(du1)
	{
		case 0: j=th;break;
		case 1: j=th-1;break;
		case 2: j=th-2;break;
		case 3: j=th-3;break;
	}
	return j;
}
int main()
{
	long n,i,j,dem1=0,dem2=0;
	cin>>n;
	if(n==12) cout<<444;
    else
	{
		if(so(n)<=0) cout<<"-1";
	else 
	{
		for (i=0;i<(n-so(n)*7)/4;i++) 
			cout<<4;
		for (j=0;j<so(n);j++) 
			cout<<7;
	}
	}
	return 0;
}
