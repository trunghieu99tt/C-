#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;
int CountDiv(long n)
{
	int counter=0;
	long i=1;
	while(i*i<=n)
	{
		if(n%i==0)
		{
			if(i%2==0) counter++;
			if(n/i!=i && (n/i)%2==0) counter++;
		}
		i++;
	}
	return counter;
}
int main()
{
	int t,k;
	cin>>t;
	for (k=0;k<t;k++)
	{
		long n;
		cin>>n;
		cout<<CountDiv(n)<<endl;
	}
	return 0;
}