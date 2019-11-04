#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int dem=1,n,i,j;
	n=s.length();
	for (i=1;i<n;i++)
	{
		bool flag=true;
		for (j=i-1;j>=0;j--)
		 if(s[j]==s[i])
		 {
		 	flag=false;
		 	break;
		 }
		if(flag==true) dem++;
	}
	if(dem%2!=0) cout<<"IGNORE HIM!";
	else cout<<"CHAT WITH HER!";
	return 0;
}
