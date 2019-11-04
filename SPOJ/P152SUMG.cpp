#include<iostream>
#include<math.h>
using namespace std;
int kt(int n)
{
	if(n==1) return 0;
	int dem=0;
	for (int i=1;i<=sqrt(n);i++) if(n%i==0) dem++;
	if(dem==1) return 1; else return 0;
}
int main()
{
		int x,y;
	cin>>x>>y;
    bool flag=true;
    for (int i=x+1;i<y;i++) 
    {
    	if(kt(i)==1) 
    	{
    		flag=false;
    		cout<<"NO";
    		break;
		}
	}
	if(flag==true)
	{
		if(kt(y)==1) cout<<"YES";
		else cout<<"NO";
	}
	return 0;
}
