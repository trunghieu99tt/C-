/*
   Thuật toán: 
     Sàng nguyên tố;
     duyệt từ cuối mảng nguyên tố về đầu ,mỗi lần duyệt chuyển số đó sang chuỗi, xác định xem chuỗi đó có nằm trong chuỗi ban đầu hay không
     nếu có thì break.
 */
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdio.h>
#define maxn 100000
using namespace std;
int snt[maxn+1],i,j;
void sangnt()
{
	for (i=1;i<=maxn;i++) snt[i]=1;
	snt[1]=0;
	i=2;
	while(i<=sqrt(maxn))
	{
		while(snt[i]==0) i++;
		for (j=2;j<=maxn/i;j++) snt[i*j]=0;
		i++;
	}
}
int main()
{
	sangnt();
	while(1)
    {
        char a[256];
    	cin>>a;
        if(strlen(a)==1 && a[0]-'0'==0) break;
    	else
    	{
    		for (i=maxn;i>=2;i--)
    	{
    		int n=i;
    		if(snt[n]==1)
    		{
    		    char c[10];
    		    sprintf(c,"%d",n);
    			if(strstr(a,c))
    			{
    				cout<<n<<endl;
    			    break;
				}
			}
		}
		}
    }
    return 0;
}
