#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;
int main()
{
	int t,k;
	cin>>t;
	for (k=0;k<t;k++)
	{
		int n;
		cin>>n;
		int a[n],i,j;
		vector<int> a1;
		for (i=0;i<n;i++)
		{
			 cin>>a[i];
			 a1.push_back(a[i]);
		}
		vector<int> res;
		res.push_back(*max_element(a,a+n));
		int k=1;
		while(k<n)
		{
			vector<int> temp;
			for (i=0;i<a1.size()-1;i++)
				temp.push_back(min(a1[i],a1[i+1]));
			res.push_back(*max_element(temp.begin(),temp.end()));
			a1=temp;
			k++;
		}
		for (auto i:res)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}