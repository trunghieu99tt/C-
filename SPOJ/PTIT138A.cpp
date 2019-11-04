#include<iostream>
using namespace std;
int kt(int a, int b, int c)
{
	if(a*a+b*b==c*c) return 1; else return 0;
}
int main()
{
	while(1)
	{
		int a,b,c;
	cin>>a>>b>>c;
	if(a==0 && b==0 && c==0) return 0;
	if(kt(a,b,c)==1 || kt(a,c,b)==1 || kt(b,c,a)==1 ) cout<<"right"<<endl;
	else cout<<"wrong"<<endl;
	}
	return 0;
}
