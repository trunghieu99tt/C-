#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string s;
    while (1)
    {
    	cin>>s;
    	if(s=="#") break;
    	else 
		{
			long demy=0,demn=0,demp=0,dema=0;
		for (long i=0;i<s.length();i++)
		{
			if(s[i]=='Y') demy++;
			else if(s[i]=='N') demn++;
			else if(s[i]=='P') demp++;
			else if(s[i]=='A') dema++;
		}
		if(float(dema)>=float(s.length())/2.0) cout<<"need quorum"<<endl;
		else 
		{
			if(demy>demn) cout<<"yes"<<endl;
		    else if(demn>demy) cout<<"no"<<endl;
		    else cout<<"tie"<<endl;
		}
		}
	}
	return 0;
}
