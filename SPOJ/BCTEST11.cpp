#include<iostream>
using namespace std;
int main()
{
	int a[]={4,7,44,47,77,444,447,477,474,744,747,774,777};
	int n,i;
	bool flag=false;
	cin>>n;
	for (i=0;i<13;i++) 
	{
		if(n%a[i]==0) 
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}
