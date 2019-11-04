#include<iostream>
using namespace std;
int stringtonum(char s)
{
	return s-'0';
}
char numtostring(int n)
{
	return (char)(n+48);
}
void chuanhoa(string &a, string &b)
{
	int l1=a.length(),l2=b.length(),i;
	if(l1>l2)
	{
		for (i=0;i<l1-l2;i++) b='0'+b;
	}
	else 
	{
		for (i=0;i<l2-l1;i++) a='0'+a;
	};
}
string sum(string a, string b)
{
	string s="";
	chuanhoa(a,b);
	int l=a.length();
	int temp=0,i;
	for (i=l-1;i>=0;i--)
	{
		temp=stringtonum(a[i])+stringtonum(b[i])+temp;
		s=numtostring(temp%10)+s;
		temp=temp/10;
	}
	if(temp>0) s=numtostring(temp)+s;
	return s;
}
string tru(string a, string b)
{
	string s="";
	chuanhoa(a,b);
	int l=a.length();
	int temp=0,i,j,k;
	for (i=l-1;i>=1;i--)
	{
		int t,d,h;
		t=stringtonum(a[i]);d=stringtonum(b[i]);
		if(t<d)
		{
			 t+=10;
			 int k=stringtonum(b[i-1]);
			 k+=1;
			 b[i-1]=numtostring(k);
		}
		h=t-d;
		s=numtostring(h)+s;
	}
	j=stringtonum(a[0]),k=stringtonum(b[0]);
	s=numtostring(j-k)+s;
	return s;
}
string nhannho(char a, string b)
{
	string s="";
	int l=b.length();
	int temp=0,i;
	for (i=l-1;i>=0;i--)
	{
		temp=stringtonum(a)*stringtonum(b[i])+temp;
		s=numtostring(temp%10)+s;
		temp=temp/10;
	}
	if(temp>0) s=numtostring(temp)+s;
	return s;
}
string nhan(string a, string b)
{
	string s="";
	int l=a.length();
	string s1[l];
	for (int i=l-1;i>=0;i--)
	{
		s1[i]=nhannho(a[i],b);
		for (int j=0;j<l-i-1;j++) s1[i]+='0';
		s=sum(s,s1[i]);
	}
	return s;
}
int demsokhong(string s)
{
	int i=0,dem=0;
	while(s[i]=='0')
	{
		dem++;
		i++;
	}
	return dem;
}
string xoasokhong(string s)
{
	string b="";
	for (int i=demsokhong(s);i<s.length();i++) b+=s[i];
	return b;
}
int kt(string a,string b)
{
	if(a.length()==b.length()) 
	{
		for (int i=0;i<a.length();i++) 
		{
			if(a[i]!=b[i])
			{
				return 0;
			}
		}
		return 1;
	}
	else return 0;
}
int main()
{
	string a, b,d,e;
	cin>>a>>b;
	chuanhoa(a,b);
	if((a[0]-48)>(b[0]-48))
	{
		d=sum(a,b);
		xoasokhong(d);
		cout<<d<<endl;
		if(kt(a,b)==1) cout<<"0"<<endl;
		else
		{
		string c=tru(a,b);
			xoasokhong(c);
	     cout<<c<<endl;
		}
	e=nhan(a,b);
	e=xoasokhong(e);
	cout<<e;
	}
	else
	{
	d=sum(a,b);
		xoasokhong(d);
		cout<<d<<endl;
	if(kt(a,b)==1) cout<<"0"<<endl;
		else
		{
		string c=tru(a,b);
			xoasokhong(c);
	     cout<<"-"<<c<<endl;
		}
e=nhan(a,b);
	e=xoasokhong(e);
	cout<<e;
	}
}
