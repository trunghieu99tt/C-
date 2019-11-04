#include<iostream>
using namespace std;
int kt(string s,int n)
{
	int i;
	string b="";
	for (i=n;i<n+3;i++) b+=s[i];
	if(b=="TTT") return 1;
	else if(b=="TTH") return 2;
	else if(b=="THT") return 3;
	else if(b=="THH") return 4;
	else if(b=="HTT") return 5;
	else if(b=="HTH") return 6;
	else if(b=="HHT") return 7;
	else return 8;
}
int main()
{
	int t,k;
	cin>>t;
	cin.ignore();
	for (k=0;k<t;k++)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int a[9],i,j;
		for (i=1;i<=8;i++) a[i]=0;
		for (i=0;i<s.length()-2;i++)
		 {
		 	for (j=1;j<=8;j++)
		 	{
		 		if(kt(s,i)==j)
		 		{
		 			a[j]++;
		 			break;
				 }
			 }
		 }
		 cout<<n<<" ";
		 for (i=1;i<=7;i++) cout<<a[i]<<" ";
		 cout<<a[8];
		 cout<<endl;
	}
	return 0;
}
