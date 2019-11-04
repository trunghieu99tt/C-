#include<iostream>
using namespace std;
int main()
{
	int next[]={0,2,3,4,5,6,7,8,1},i,n,k,timeleft;
	cin>>k;
	cin>>n;
	int b[n];
	char c[n];
	for (i=0;i<n;i++) cin>>b[i]>>c[i];
	timeleft=210;
	i=0;
	while(timeleft>0)
	{
		if(c[i]=='T') 
		{
			timeleft-=b[i];
			if(timeleft>0 ) k=next[k];
			i++;
		}
		else if(c[i]=='P'|| c[i]=='N')
		{
			 timeleft-=b[i];
			 i++;
		}
		if(timeleft<0) break;
	}
	cout<<k;
	return 0;
}
