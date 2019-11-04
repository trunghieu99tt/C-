#include<iostream>
using namespace std;
int main()
{
	while(1)
	{
		int n,m;
	cin>>n>>m;
	if(n%m==0) cout<<"0";
	else
    {
    	float k;
    	lap:
    	k=float(n)/m;
    	if(k>0.5 && k<1) cout<<n;
    	else if(k<=0.5)
    	{
    		int l;
			l=int(1.0/k);
			cout<<(l-1)*n;
		}
		else if(k>1)
		{
			int j=n/m;
			n-=m*j;
			goto lap;
		}
	}
	}
	return 0;
}
