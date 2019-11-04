#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int test,k;
	cin>>test;
	for (k=0;k<test;k++)
	{
		int length,i;
		string temp;
		cin>>length;
		vector <string> s;
		for (i=0;i<length;i++)
		{
			cin>>temp;
			s.push_back(temp);
		}
		sort(s.begin(),s.end(),[](string a, string b){
			return (a+b<b+a);
		});
		string result="";
		for (auto l:s)
			result+=l;
		cout<<result<<endl;
	}
	return 0;
}