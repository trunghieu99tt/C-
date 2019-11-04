#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX_LEN 400000
using namespace std;
 
void giaithua(int n, int x)
{
	int a[MAX_LEN]={0} ,dem=0;;
	//memset(a,0,MAX_LEN);
	a[0]=1;
	int len=1; 
	int temp =0; // bien nho'
	int j;
	for(int i=2 ;i<=n ;i++)
	{
		for(j=0 ;j<len || temp!=0 ;j++)
		{
			temp = (a[j])*i +temp;
			a[j]=(temp%10);
			temp/=10;
		}
		len=j;
	}
	for(int i=len-1 ;i>=0 ;i--)
	{
		if(a[i]==x) dem++;	
	}
	cout<<dem;
}
int main()
{
	int t;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		int n,x;
	cin>>n;
	cin>>x;
	giaithua(n,x);cout<<endl;
	}
}
