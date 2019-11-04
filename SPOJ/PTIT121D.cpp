#include<iostream>
using namespace std;
int main()
{
	while(1)
	{
		
	long long n;
	cin>>n;
	string s="moo";
	int i=0,j;
	while(s.length()<n) 
	{
		string b="m";
		i+=3;
		for (j=0;j<i;j++) b+='o';
		s=s+b+s;
	}
	cout<<s[n-1];
	}
	return 0;
}
