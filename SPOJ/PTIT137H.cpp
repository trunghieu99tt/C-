#include<iostream>
using namespace std;
long long mod=1000000007;
long long DQ_luythua (long long a, long long b)
{
	if (b==0) return 1;
	if (b%2==0)
	{
		long long p=DQ_luythua (a, b/2);
		return (p*p)%mod;
	}
	else
	{
		long long p=DQ_luythua (a, b-1);
		return (p*a)%mod;
	}
}
int main()
{
	while(1)
	{
		long long tong=0;
		string s;
		int i;
		cin>>s;
		if(s=="end") return 0;
		int t=s.length();
		for (i=0;i<s.length();i++)
		{
			int k=s[i];
			if(k>=97);
			s[i]-=32;
		}
		for (i=0;i<s.length();i++)
		 {
		     int k=s[i];
		     cout<<k<<endl;
		     if(k>=48 && k<=57)  tong+=DQ_luythua(62,t-i-1)*(k-48);
		     else  tong+=DQ_luythua(62,t-i-1)*(k-55);
		 }
		cout<<tong<<endl;
		if(tong%61==0) cout<<"yes"<<endl; else cout<<"no"<<endl;
	}
	return 0;
}
