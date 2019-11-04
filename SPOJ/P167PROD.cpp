#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int kt(string s)
{
	int i,n=s.length();
	bool flag=false;
	for (i=0;i<n;i++) 
	{
		if(s[i]=='?') 
		{
			flag=true;
			break;
		}
	}
	if(flag==true) return 1; else return 0;
}
int vitri(string s)
{
	int i,n=s.length(),vitri;
    for (i=0;i<n;i++)
    {
    	if(s[i]=='?')
    	{
    		vitri=i;
    		break;
		}
	}
	return n-1-vitri;
}
long stringtonum(string s)
{
	long kq=0;
	int i,n=s.length();
	for (i=0;i<n;i++) kq+=(s[i]-48)*pow(10,n-1-i);
	return kq;
}
void numtoarray(long n, int a[])
{
	int i=0;
	a[0]=n%10;
	n/=10;
	while(n>0)
	{
		a[++i]=n%10;
		n/=10;
	}
}
void xuli1(string a, string b, string c)
{
	long k,l,m;
	int j,a1[1000];
	l=stringtonum(b); m=stringtonum(c);
		k=m-l;
		numtoarray(k,a1);
		j=vitri(a);
		cout<<a1[j];
}
void xuli2(string a, string b, string c)
{
	long k,l,m;
	int j,a1[1000];
	l=stringtonum(b); m=stringtonum(c);
		k=l+m;
		numtoarray(k,a1);
		j=vitri(a);
		cout<<a1[j];
}
int main()
{
	string a, b,c;
	cin>>a>>b>>c;
	if(kt(a)==1) xuli1(a,b,c);
	else if(kt(b)==1) xuli1(b,a,c);
	else xuli2(c,a,b);
}
