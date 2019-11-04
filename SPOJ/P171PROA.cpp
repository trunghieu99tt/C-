#include<iostream>
#include<math.h>
using namespace std;
int main()
{
		long long l,r,x,k,t=1;
	bool flag=false;
	cin>>l>>r>>x;
	k=log(r)/log(x);
	if(l==1) cout<<1<<" ";
	for (int i=0;i<k;i++)
	{
		t*=x;
		if(t>=l && t<=r) 
		{
			cout<<t<<" ";
			flag=true;
		}	
	}
	if(flag==false) cout<<"-1";
	return 0;
}
