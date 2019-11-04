#include<iostream>
using namespace std;
int kt(char a, string s)
{
    for (int i=0;i<s.length();i++) 
    	if(a==s[i]) return 1;
	return 0;
}
int vitri(char a, string s)
{
	for (int i=0;i<s.length();i++) if(a==s[i]) return i;
}
char doi1(string s, int k, int j)
{	
	 if((j+k)%3==0) return s[2];
	 else if((j+k)%3==2) return s[1];
	 else return s[0];
}
char doi2(string s, int k, int j)
{
	if((j+k)%4==0) return s[3];
	else if((j+k)%4==3) return s[2];
	else if((j+k)%4==2) return s[1];
	else return s[0];
}
char thuchien1(char a,string b, int i)
{
	int k=vitri(a,b);
	return doi1(b,k,i);
}
char thuchien2(char a, string b, int i)
{
	int k=vitri(a,b);
	return doi2(b,k,i);
}
int main()
{
	while(1)
	{
		string s,s2="abc",s3="def",s4="ghi",s5="jkl",s6="mno",s7="pqrs",s8="tuv",s9="wxyz";
		cin>>s;
		if(s=="#") return 0;
		int i,n=s.length();
		for (i=0;i<s.length();i++)
		{
			if(kt(s[i],s2)==1) s[i]=thuchien1(s[i],s2,i);
			else if(kt(s[i],s3)==1) s[i]=thuchien1(s[i],s3,i);
			else if(kt(s[i],s4)==1) s[i]=thuchien1(s[i],s4,i);
			else if(kt(s[i],s5)==1) s[i]=thuchien1(s[i],s5,i);
			else if(kt(s[i],s6)==1) s[i]=thuchien1(s[i],s6,i);
			else if(kt(s[i],s7)==1) s[i]=thuchien2(s[i],s7,i);
			else if(kt(s[i],s8)==1) s[i]=thuchien1(s[i],s8,i);
			else if(kt(s[i],s9)==1) s[i]=thuchien2(s[i],s9,i);
		}
		for (i=0;i<s.length();i++) cout<<s[i];
        cout<<endl;
	}
	return 0;
}
