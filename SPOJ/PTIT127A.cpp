#include<iostream>
using namespace std;
int main()
{
	int m,n,k;
	cin>>m>>n>>k;
	int max;
	if(m/2 > n) max=n; else max=m/2;
	if((m+n-3*max)>=k) cout<<max;
	else 
	{
		while(max!=0 && (m+n-3*max)<k) max--;
		cout<<max;
	}
	return 0;
}
