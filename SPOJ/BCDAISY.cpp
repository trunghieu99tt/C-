#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int c1[m],c2[m],i,d[n];
	for (i=1;i<=n;i++) d[i]=0;
	for (i=0;i<m;i++) cin>>c1[i]>>c2[i];
	d[c1[0]]=1;
	for (i=0;i<m;i++) 
	  {
	  	if(c1[i]==c1[0]) d[c2[i]]=1;
	  	else if(c2[i]==c1[0]) d[c1[i]]=1;
	  	else if(d[c1[i]]==1) d[c2[i]]=1;
	  	else if(d[c2[i]]==1) d[c1[i]]=1;
	   }
	bool flag=false;
	for (i=1;i<=n;i++) if(d[i]==0) 
	{
		flag=true;
		cout<<i<<endl;
	}
	if(flag==false) cout<<0;
	return 0;#
}
