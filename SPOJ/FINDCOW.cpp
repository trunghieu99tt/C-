#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int i,dem=0,tong=0;
	for (i=s.length()-1;i>=1;i--) if(s[i]==')' && s[i-1]==')') dem++;
	while(dem!=0)
	{
		for (i=0;i<s.length()-1;i++) 
		 {
		 	if(s[i]=='('&& s[i+1]=='(') tong+=dem;
		 	else if(s[i]==')' && s[i+1]==')') dem--;
		 }
	}
	cout<<tong;
	return 0;
}
