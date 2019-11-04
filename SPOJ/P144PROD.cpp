#include<iostream>
#include<string.h>
using namespace std;
int kt(char a[][51], int n)
{
	bool flag=true;
	for (int i=1;i<n;i++) 
	  if(a[i]!=a[0]) 
	  {
	  	flag=false;
	  	break;
	  }
	if(flag==true) return 1; else return 0;
}
void xoakitu(string a)
{
	while(a[0]=='0') strcpy(a,a+1);
}
void themkytu(string a, int n)
{
	while(s.length(a)!=n) s='0'+s;
}
int main()
{
	while(1)
	{
		int dem=1,i;
		int n;
		char max[51],min[51];
		cin>>n;
		if(n==0) return 0;
		char a[n][51];
		for (i=0;i<n;i++) 
		{
			cin>>a[i];
		}
		lenmax=s[0].length()
		if(kt(a,n)==1) cout<<"case "<<dem<<" : There is a row of trees having equal height"<<endl;
		else 
		{
			strcpy(max,a[0]);
			strcpy(min,a[0]);
			for (i=1;i<n;i++)
			 {
			 	if(strlen(a[i])>strlen(max)) strcpy(max,a[i]);
			 	else if(strlen(a[i])==strlen(max) && a[i]>max)strcpy(max,a[i]);
				else if(strlen(a[i])<strlen(min)) strcpy(max,a[i]);
			 	else if (strlen(a[i])==strlen(min) && a[i]<min)strcpy(min,a[i]);
			 }
			 cout<<"case "<<dem<<" : "<<min<<" "<<max<<endl;
		}
		dem++;
	}
	return 0;
	}
