#include<iostream>
using namespace std;
int main()
{

	int n;
	cin>>n;
	int a[n],i,dem=0;
	for (i=0;i<n;i++) 
	{
		cin>>a[i];
		if(a[i]==0) dem++;
	}
	if(dem!=1) cout<<"NO"; else cout<<"YES";
	return 0;
}
