#include<iostream>
#include<math.h>
#define short 32767
#define int1 2147483647
using namespace std;
long long stringtonum1(string s)
{
	long long n=0;
	for (int i=0;i<s.length();i++) 
	{
		n+=pow(10,s.length()-i-1)*(s[i]-48);
	}
	return n;
}
int main()
{
	while(1)
	{
		string s;
	cin>>s;
	int t;
	t=s.length();
	if(t>19) cout<<"BigInteger";
	else 
	{
		if(t<19)
		{
			string b=s;
		long long n;
		n=stringtonum1(s);
		if(n<=127) cout<<"byte";
		else if(n<=short ) cout<<"short";
		else if( n<=int1) cout<<"int";
		else  cout<<"long";
		}
		else if(t==19)
		{
			if(s[18]-48 <=8) cout<<"long";
			else cout<<"BigInteger";
		}
	}
	}
	return 0;
}
