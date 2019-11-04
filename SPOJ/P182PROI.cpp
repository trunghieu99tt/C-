#include <iostream>
#include<string>
#include<math.h>
using namespace std;
string NumtoBin(long long n)
{
	string s="";
	while(n/2!=0)
	{
		s+=(n%2+'0');
		n/=2;
	}
	return s;
}
int main()
{
	long long n,dem=0,i;
	cin>>n;
	string s=NumtoBin(n);
	for (i=0;i<s.length();i++) if(s[i]=='0') dem++;
	long long k=pow(2,dem);
	cout<<k;
	return 0;
}