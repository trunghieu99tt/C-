#include<iostream>
using namespace std;
string xuli(string a, string b, int n)
{
	string s="";
	int i;
	for (i=0;i<n;i++) 
	{
		s+=a[i];
		s+=b[i];
	}
	return s;
}
int main()
{
	while(1)
	{
		int n;
		cin>>n;
		if(n==0) return 0;
		int i,dem=1;
		string s1,s2,s,b;
		cin>>s1>>s2>>s;
	    b=xuli(s2,s1,n);
		if(b==s) cout<<dem<<endl;
		else 
		{
			while(1)
			{
				dem++;
				string b1="",b2="";
				for (i=0;i<n;i++) b1+=b[i];
				for (i=n;i<2*n;i++) b2+=b[i];
				b=xuli(b2,b1,n);
				if(b==s)
				{
					cout<<dem<<endl;
					break;
				}
				if(dem>50) 
				{
					cout<<-1<<endl;
					break;
				}
			}
		}
	}
}
