#include<iostream>
using namespace std;
int main()
{
	long long k,n,demchan,demle;
	cin>>n>>k;
	if(n%2==0) 
	{
		demchan=(n-2)/2+1;
		demle=(n-2)/2+1;
	}
	else 
	{
		demchan=(n-3)/2+1;
		demle=(n-1)/2+1;
	}
	if(k>demle) cout<<(k-demle)*2; else cout<<(k*2-1);
	return 0;
}

