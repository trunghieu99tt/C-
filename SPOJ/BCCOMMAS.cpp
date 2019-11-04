#include<iostream>
using namespace std;
int main()
{
    	string s,b="";                 // khoi tao chuoi b 
    int i,j,dem=0;
	cin>>s;
	i=s.length()-1;
	while(i>=0)
	{
		b=s[i]+b;
		dem++;
		if(dem%3==0) b=','+b;                  
		i--;
	}
	if(b[0]==',') for (i=1;i<b.length();i++) cout<<b[i];              // chuan hoa chuoi, neu co dau "," o dau thi xuat chuoi tu ki tu thu 2
	else for (i=0;i<b.length();i++) cout<<b[i];                      
	return 0;
}
