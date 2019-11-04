#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;
int Compare(string a, string b)
{
	if(a.length()<b.length()) return 1;
	else if(a.length()==b.length())
	{
		if(a>b) return 0;
		else return 1;
	}
	return 0;
}
int main()
{
	int n,i;
	cin>>n;
	string res;
	string id[n],hero[n],result[n];
	for (int i=0;i<n;i++)
	{
		cin>>id[i]>>hero[i]>>result[i];
		if(hero[i]=="AM" && result[i]=="W")
			res=id[i];
	}
	for (i=0;i<n;i++)
	{
		if(hero[i]=="AM" && result[i]=="W" && Compare(res,id[i])==0)
			res=id[i];
	}
	cout<<res;
	return 0;
}