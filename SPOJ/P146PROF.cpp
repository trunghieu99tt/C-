#include<iostream>
using namespace std;
int kt(int a, int b, int c)
{
	if(a+b>c&& b+c>a && a+c>b) return 1; else return 0;
}
int kt1(int a, int b, int c)
{
	if(a+b==c || b+c==a || a+c==b) return 1; else return 0;
}
int main()
{
		int a, b,c ,d;
	cin>>a>>b>>c>>d;
	if(kt(a,b,c)==1||kt(a,b,d)==1 || kt(b,c,d)==1 || kt(a,c,d)==1) cout<<"TRIANGLE";
	else if(kt1(a,b,c)==1||kt1(a,b,d)==1 || kt1(b,c,d)==1 || kt1(a,c,d)==1) cout<<"SEGMENT";
	else cout<<"IMPOSSIBLE";
	return 0;
}
