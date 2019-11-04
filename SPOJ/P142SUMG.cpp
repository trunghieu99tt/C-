#include<iostream>
using namespace std;
int main()
{
	int t,k;
	cin>>t;
	cin.ignore();
	for (k=0;k<t;k++)
	{
		int i,a[33],dem,vitrimax,max,d;
		bool flag=true;
		for (i=65;i<=90;i++) a[i]=0;
		string s;
		getline(cin,s);
		for (i=0;i<s.length();i++)
		{
			if(s[i]!=' ')
			{
				int t=s[i];
				a[t]++;
			}
		}
		max=a[65];
		dem=0;
		for (i=65;i<=90;i++) 
		{
			if(a[i]>=max) max=a[i];
		}
		for (i=65;i<=90;i++)
		{
			if(a[i]==max) 
			{
				dem++;
				vitrimax=i;
			}
			if (dem==2)
			{
				flag=false;
				break;
			}
		}
		if(flag==false) cout<<"NOT POSSIBLE"<<endl;
		else
		{
			if(vitrimax>69) 
				d=vitrimax-69;
				else d=69-vitrimax+21;
				cout<<d<<" ";
			for (i=0;i<s.length();i++)
			{
				if(s[i]!=' ') 
				{
					if(s[i]-d>=65) 
					{
						s[i]-=d;cout<<s[i];
					}
					else 
					{
						int l=65-(s[i]-d);
						char c=91-l;
						cout<<c;
					}
				}
				else cout<<s[i];
			}
			cout<<endl;
		}
	}
}
