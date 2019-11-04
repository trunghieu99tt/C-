#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n,i,j;
    cin>>n;
    for (i=0;i<n;i++)
    {
    	int dem=0;
    	int a,b;
    	cin>>a>>b;
    	for (j=a;j<b;j++) if(s[j]==s[j+1]) dem++;
    	cout<<dem<<endl;
    }
    return 0;
}
