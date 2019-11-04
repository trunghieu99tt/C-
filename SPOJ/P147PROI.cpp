#include<iostream>
#include<stdlib.h>
using namespace std;
int ucln(int a, int b)
{
	while(a!=0 && b!=0)
	{
		if(a>b)a-=b; else b-=a;
	}
	if(a==0) return b; else return a;
}
int main()
{
    	int n,m;
    cin>>n>>m;
    int a[n],b[m],i,j;
    for (i=0;i<=n;i++) cin>>a[i];
    for (j=0;j<=m;j++) cin>>b[j];
    if(n>m) 
    {
    	if(a[0]*b[0]>0) cout<<"Infinity";
    	else cout<<"-Infinity";
	}
	else if(n<m) cout<<"0/1";
	else
	{
		int l=ucln(abs(a[0]),abs(b[0]));
		if(a[0]*b[0]>0) 
		{
			if(a[0]>0 && b[0]>0) cout<<a[0]/l<<"/"<<b[0]/l;
			else cout<<-a[0]/l<<"/"<<-b[0]/l;
		}
		else if(a[0]>0 && b[0]<0) cout<<-a[0]/l<<"/"<<-b[0]/l;
		else if(a[0]<0 && b[0]>0) cout<<a[0]/l<<"/"<<b[0]/l;
	}
	return 0;
}
