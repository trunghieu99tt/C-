#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	while (s.length()%3!=0) s="0"+s;
	for (long i=0;i<=s.length()-3;i+=3)
	{
		string b;
		b="";
		for (long j=i;j<i+3;j++) 
			b+=s[j];
			if(b=="000") cout<<0; 
			else if(b=="001") cout<<1;
			else if(b=="010") cout<<2;
			else if(b=="011") cout<<3;
			else if(b=="100") cout<<4;
			else if(b=="101") cout<<5;
			else if(b=="110") cout<<6;
			else if(b=="111") cout<<7;
	}
	return 0;
}
