#include<iostream>
using namespace std;
int kt(long long a)
{
	if(a%2==0 || a%3==0 || a%5==0) return 1; else return 0;
}
int xuliso(long long &a)
{
	if(a%2==0) a/=2;
	else if(a%3==0) a=a/3;
	else if(a%5==0) a=a/5;
	return a;
}
int main()
{
	long long a,b;
	bool flag=true;
	int dem=0;
	cin>>a>>b;
	while(a!=b)
	{
		if(a>b)
		{
			a=xuliso(a);
			dem++;
			if(a==b) break;
			else {
				b=xuliso(b);
			dem++;
			}
		}
		else
		{
			b=xuliso(b);
			dem++;
			if(a==b) break;
			else 
			{
				a=xuliso(a);
			dem++;
			}
		}
		if((kt(a)==0||kt(b)==0)&&(a!=b))
		{
			flag=false;
			break;
		}
	}
	if(flag==true )cout<<dem; else cout<<"-1";
	return 0;
}
