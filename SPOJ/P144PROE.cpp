#include<iostream>
using namespace std;
int main()
{
	int x,y,a,b,i,j,dem=0;
	bool flag=true;
	cin>>x>>y>>a>>b;
	if(y>x && a==b && a==x ) cout<<0;
	else
	{
		i=a;j=b;
		if(i==j) i++;						
		else if(i<j)
		{
			while(i<j && i<=x) i++;								// cả 1 đoạn mục đích tăng i đến khi i>j
				if(i<j) 
				{
					cout<<0;
					flag=false;
				}
		}
		if(flag==true)
			{
				int tam1=i,tam2=j
				while(tam1<=x)
				{
					tam2=b;
					while(tam2<=y && tam2<tam1)
					{
						dem++;
						tam2++;
					}
					tam1++;
				}
				cout<<dem<<endl;
				while(i<=x)
				{
					j=b;
					while(j<=y && j<i) 
					{
						cout<<i<<" "<<j;
						cout<<endl;
						j++;
					}
				i++;
				}
			}
	}
		
	return 0;
}