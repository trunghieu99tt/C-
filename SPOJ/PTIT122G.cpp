#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
bool AreAll9s(string s)
{
	return (count(s.begin(),s.end(),'9')==s.length());
}
void generateNexPalindromeUtil(string k)
{
	vector<int> a;
	for (auto i:k)
		a.push_back(i-'0');
	int n=k.length(),mid=n/2,i=mid-1,j=(n%2)?mid+1:mid;
	bool leftsmaller=false;
	while(i>=0 && a[i]==a[j])
	{
		i--;
		j++;
	}
	if(i<0 || a[i]<a[j])
		leftsmaller=true;
	while(i>=0)
	{
		a[j]=a[i];
		j++;
		i--;
	}
	if(leftsmaller==true)
	{
		int carry=1;
		i=mid-1;
		if(n%2==1)
		{
			a[mid]+=carry;
			carry=a[mid]/10;
			a[mid]%=10;
			j=mid+1;
		}
		else j=mid;
		while(i>=0)
		{
			a[i]+=carry;
			carry=a[i]/10;
			a[i]%=10;
			a[j++]=a[i--];
		}
	}
	long res=0;
	for (auto i: a)
		res=res*10+i;
	cout<<res-stoi(k,nullptr,10)<<endl;
}
void generateNexPalindrome(string n)
{
	int i,k=n.length();
	string s="1";
	if(AreAll9s(n))
	{
		for (i=0;i<k-2;i++) s+='0';
		s+='1';
		cout<<stoi(s,nullptr,10)-stoi(n,nullptr,10)<<endl;
	}
	else
		generateNexPalindromeUtil(n);
}
bool CheckPalindrome(string n)
{
	string temp=n;
	reverse(temp.begin(),temp.end());
	return (temp==n);
}
int main()
{
	while(1)
	{
		string n;
		cin>>n;
		if(n=="0") return 0;
		if(CheckPalindrome(n)==1) cout<<0<<endl;
		else
		generateNexPalindrome(n);
	}
}
