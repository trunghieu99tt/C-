#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	while(1)
	{
		int n,counter=0;
		cin>>n;
		if(n==0) return 0;
		string s1,s2,s;
		cin>>s1>>s2>>s;
		while(1)
		{
			string tempresult="";
			for (int i=0;i<n;i++)
			{
				tempresult+=s2[i];
				tempresult+=s1[i];
			}
			counter++;
			if(tempresult==s)
				{
					cout<<counter<<endl;
					break;
				}
			s1=tempresult.substr(0,tempresult.length()/2);
			s2=tempresult.substr(tempresult.length()/2);
			if(counter>50)
				{
					cout<<-1<<endl;
					break;
				}
		}
	}
} 