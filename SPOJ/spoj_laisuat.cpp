#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long n;
	cin>>n;
	for (long i=0;i<n;i++)
	{
		double n,l,m;
		cin>>n>>l>>m;
		cout<<int(float(log(m/n))/log(1+l/100.00))+1<<endl;
	}
	return 0;
}
