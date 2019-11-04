#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;
int Check(vector<int> a, vector<int> b)
{
	int i,counter=0;
	for (i=0;i<a.size();i++)
		if(a[i]!=b[i]) counter++;
	if(counter>2) return 0;
	return 1;
}
int main()
{
	int t,k;
	cin>>t;
	for (k=0;k<t;k++)
	{
		string s;
		cin>>s;
		vector<int> digit;
		for (auto i:s)
		{
			digit.push_back(i-'0');
		}
		bool flag=true;
		auto compare=digit;
		do
		{
			prev_permutation(digit.begin(),digit.end());
			if(digit[0]==0)
			{
				flag=false;
				break;
			}

		}
		while(Check(compare,digit)==0);
		if(flag==false) cout<<"-1"<<endl;
		else if(compare==digit) cout<<"-1"<<endl;
		else
		{
			for (auto i:digit)
				cout<<i;
			cout<<endl;
		}
	}
	return 0;
}