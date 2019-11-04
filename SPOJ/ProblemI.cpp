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
		long long x,y,z,n;
		cin>>x>>y>>z>>n;
		long long temp=round(pow(10,n-1));
		unsigned long long temp1=round(pow(10,n));
		long long g1=__gcd(x,y),l1=(x*y)/g1, g2=__gcd(l1,z),l2=(l1*z)/g2;
		if(l2>=temp1) cout<<-1<<endl;
		else
		{
			long long mod=temp%l2;
			if(mod==0) cout<<temp;
			// cout<<mod<<" "<<temp/l2;
			else cout<<(l2*(temp/l2+1))<<endl;
		}
	}
	return 0;
} 
