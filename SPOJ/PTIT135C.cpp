#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	long a[n];
	for (i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
	long d=a[n-1]-a[0];
	vector<long> v;
	vector<long>v1;
	for (i=1;i*i<=d;i++)
		{
			if(d%i==0) 
			{
				v.push_back(i);
				if(i!=d/i) v.push_back(d/i);
			}
		}
	for (i=0;i<v.size();i++)
	{
		long temp=a[0]%v[i];
		bool flag=true;
		for (j=1;j<n;j++)
		{
			if(a[j]%v[i]!=temp)
			{
				flag=false;
				break;
			}
		}
		if(flag==true && v[i]>1) v1.push_back(v[i]);
	}
	sort(v1.begin(),v1.end());
	for (i=0;i<v1.size();i++) cout<<v1[i]<<" ";
	return 0;
}