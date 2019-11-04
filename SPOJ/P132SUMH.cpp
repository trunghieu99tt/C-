#include<iostream>
using namespace std;
int kt(int n, int a, int k)
{
	bool flag;
	if(n<=a) flag=true;
	else
	{
		if(n>a && n<=k) flag=false;
		else if(n>a)
		{
			int l=n%k;
			if(l>=0 && l<=a) flag=true; else flag=false;
		}
	}
	if(flag==true) return 1; else return 0;
}
void kq(int n, int a, int k, int l, int b)
{
	if(kt(n,a,k)==1 &&kt(n,b,l)==1) cout<<"both";
	else if(kt(n,a,k)==1 && kt(n,b,l)==0||kt(n,a,k)==0 && kt(n,b,l)==1 ) cout<<"one";
	else cout<<"none";
}
int main()
{
	int a,b,c,d,p,m,q;
	bool flag1,flag2,flag3;
	cin>>a>>b>>c>>d;
	cin>>p>>m>>q;
	int k,l;
	k=a+b;
	l=c+d;
	kq(p,a,k,l,c);cout<<endl;
	kq(m,a,k,l,c);cout<<endl;
	kq(q,a,k,l,c);cout<<endl;
	return 0;
}
