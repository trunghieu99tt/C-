#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
	int t,k;
	cin>>t;
	for (k=0;k<t;k++)
	{
		int b;
		long long n,res=0;
		cin>>b>>n;
		vector<int> temp;
		while(n)
		{
			temp.push_back(n%b);
			n/=b;
		}
		for (auto i:temp)
			res+=round(pow(i,2));
		cout<<res<<endl;
	}
	return 0;
}