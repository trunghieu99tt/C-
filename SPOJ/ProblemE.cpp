#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;
int findPoint(int a[],int n)
{
	long leftSum=0;
	for (int i=0;i<n;i++)
	{
		leftSum+=a[i];
		long rightSum=0;
		for (int j=i+1;j<n;j++)
			rightSum+=a[j];
		if(leftSum==rightSum)
			return i+1;
	}
	return -1;
}
void Result(int a[],int n)
{
	int point=findPoint(a,n);
	if(point==-1 || point==n)
		cout<<"NO"<<endl;
	else 
	{
		vector<int> temp1;
		vector<int> temp2;
		for (int i=0;i<point;i++)
			temp1.push_back(a[i]);
		for (int i=point;i<n;i++)
			temp2.push_back(a[i]);
		if(temp1!=temp2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
int main()
{
	int t,k;
	cin>>t;
	for (k=0;k<t;k++)
	{
		int n;
		cin>>n;
		int a[n],i;
		for (i=0;i<n;i++) cin>>a[i];
		Result(a,n);
	}
	return 0;
}