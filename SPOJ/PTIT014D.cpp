#include<iostream>
#include<math.h>
using namespace std;
int sochuso(int n)
{
	int dem=0;
	while(n>0)
	{
		dem++;
		n/=10;
	}
	return dem;
}
int tong(string s)
{
	int tong=0,i;
	for (i=0;i<s.length();i++) tong+=s[i]-48;
	return tong;
}
int kq(int n)
{
	
	while (sochuso(n)!=1)
	{
		int kq=0;
		while (n>0)
	  {
		int k=pow(10,sochuso(n)-1);
		kq+=n/k;
		n%=k;
	   }
	   n=kq;
	}
	return n;
}
int main()
{
	int n;
	cin>>n;
	for (int j=0;j<n;j++)
	{
		string s;
		int t;
	cin>>s;
	if(s.length()==1 && (s[0]-48)==0) cout<<0<<endl;
	else
	{
		t=tong(s);
	if(kq(t)%9==0) cout<<1<<endl; else cout<<0<<endl;
	}
	}
}

