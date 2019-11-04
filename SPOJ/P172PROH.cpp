#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i=0,dem=0;
    while(i<s.length())
    {
    	if(s[i]=='c')
    	{
    		if(i+1<s.length())
    		{
    			if(s[i+1]=='=') 
    			{
    				dem++;
    				i+=2;
				}
				else if(s[i+1]=='-')
				{
					dem++;
					i+=2;
				}
				else 
	        	{
	        	dem++;
	        	i++;
				}
			}
			else
			{
				dem++;
				break;
			}
		}
		else if(s[i]=='d')
		{
			if(i+2<s.length() &&s[i+1]=='z' && s[i+2]=='=')
			{
					dem++;
					i+=3;
			}
			else if(i+1<s.length() && s[i+1]=='-')
			{
					dem++;
					i+=2;
			}
			else 
			{
				dem++;
				i++;
			}
			
		}
		else if(s[i]=='l')
		{
			if(i+1<s.length())
			{
				if(s[i+1]=='j')
				{
					dem++;
					i+=2;
				}
				else
			   { 
				dem++;
				i++;
			   }
			}
			else 
			{
				dem++;
				break;
			}
		}
		else if(s[i]=='n')
		{
				if(i+1<s.length())
			{
				if(s[i+1]=='j')
				{
					dem++;
					i+=2;
				}
				else
				{
				dem++;
				i++;
				}	
			}
			else
			{
				dem++;
				break;
			}
		}
		else if(s[i]=='s')
		{
			if(i+1<s.length())
			{
				if(s[i+1]=='=')
				{
					dem++;
					i+=2;
				}
				else 
				{
					dem++;
					i++;
				}
			}
			else 
			{
				dem++;
				break;
			}
		}
		else if(s[i]=='z')
		{
			if(i+1<s.length())
			{
				if(s[i+1]=='=')
				{
					dem++;
					i+=2;
				}
				else
			{
				dem++;
				i++;
			}	
			}
			else
			{
				dem++;
				break;
			}	
		}
		else
		{
			dem++;
			i++;
		}
	}
	cout<<dem;
	return 0;
}
