#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for (int j=0;j<t;j++)
	{
		string s;
	cin>>s;
	int dem=0, len=s.length();
	bool flag=true;
	for (int i=0;i<len;i++)
	{
		if((i+1)%2==0 && (s[i]-48)%2==0 || (i+1)%2!=0 && (s[i]-48)%2!=0) dem++;
		else 
		{
			flag=false ;
			break;
		}
	}
	if(flag==false) cout<<"NO"<<endl;
	else if(dem==len) cout<<"YES"<<endl;
	}
	return 0;
}
