#include<iostream>
using namespace std;
int kt(int a, int b, int c)
{
	if(a+b==c) return 1;
	else if(a*b==c) return 2;
	else if(a/b==c) return 3;
}
int main()
{
	int a, b, c;
	cin>>a>>b>>c;
	if(kt(c,b,a)==1) 
     	{
     		cout<<a<<"="<<b<<"+"<<c;
     		return 0;
		 }
	if(c==1 && b==a) 
	{
		cout<<a<<"="<<b<<"/"<<c;
		return 0;
	}
	else if(kt(b,c,a)==3) 
	{
		cout<<a<<"="<<b<<"/"<<c;
		return 0;
	}
	else if(kt(c,b,a)==2) 
	{
		cout<<a<<"="<<b<<"*"<<c;
		return 0;
	}
	else if(kt(a,b,c)==1) {
		cout<<a<<"+"<<b<<"="<<c;
		return 0;
	}
	else if(kt(a,b,c)==3) 
	{
		cout<<a<<"/"<<b<<"="<<c;
		return 0;
	}
	else if(kt(a,b,c)==2) 
	{
		cout<<a<<"*"<<b<<"="<<c;
		return 0;
	}
	else if(b>c && (b-c)==a) 
	{
		cout<<a<<"="<<b<<"-"<<c;
		return 0;
	}
	else if(a>b && (a-b)==c)
	{
		cout<<a<<"="<<b<<"-"<<c;
		return 0;
   }
}
