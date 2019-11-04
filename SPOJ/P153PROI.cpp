#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main()
{
	int m,k;
	cin>>m;
	for (k=0;k<m;k++)
	{
		char s[100000];
		gets(s);
		int a[50],n,i,j,dem=0;
	    for ( i=97;i<=122;i++) a[i]=0; // khoi tao mang gia tri cua cac ki tu
	    n=strlen(s);
	    for (i=0;i<n;i++) 
	    {
	    	if(s[i]!=' ' && s[i]>=65 && s[i]<=90) s[i]+=32;   // chuan hoa xau ve full ki tu thuong
		}
		for (i=0;i<n;i++)
		{
			if(s[i]!=' ' )
			{
				j=s[i];
				a[j]++;                              // dem so lan xuat hien cua ki tu
			}
		}
		for (i=97;i<=122;i++)
		{
			if(a[i]>1) dem+=a[i];            // gia tri cua mat thu
		}
		cout<<dem<<" "<<s[0];
		for (i=1;i<n;i++)
		{
			bool flag=true;
			j=s[i];
			if(a[j]>=1)
			{
				for (int l=i-1;l>=0;l--)
				  if(s[l]==s[i])
				  {
				  	flag=false;
				  	break;
				  }
				if(flag==true) cout<<s[i];
			}
		}
		cout<<endl;
	}
	return 0;
}

