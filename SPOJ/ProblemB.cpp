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
		int n;
		cin>>n;
		int a[n],b[n],i;
		for (i=0;i<n;i++) cin>>a[i];
		for (i=0;i<n;i++) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		bool flag=true;
		for (i=0;i<n;i++)
		{
			if(a[i]>b[i]) 
			{
				flag=false;
				break;
			}
		}
		if(flag==true) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}