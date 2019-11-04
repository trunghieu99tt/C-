#include<iostream>
#include<string.h>
using namespace std;
int chia(int n, int m)
{
	int i=1;
	while(n*i<=m)
	 {
	 	i++;
	 	m+=2;
	 }
	return (i-1);
}
int main()
{
	void *p;
	char *k;
	int n,b[100],c[100],dem=0,max,vitri;
	char a[100][16];
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>(a[i]);cout<<endl;
		cin>>b[i]; cin>>c[i];
	}
	max=chia(b[0],c[0]);
	for (int i=0;i<n;i++)
	{
		dem+=chia(b[i],c[i]);
	    if(chia(b[i],c[i])>max)
	    {
	    	max=chia(b[i],c[i]);
	    	vitri=i;
		}
	}
	cout<<dem<<endl;
	cout<<a[vitri]<<endl;
	return 0;
}
