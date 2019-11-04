#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int k=1;
	while(1)
	{
		string a,b;
		cin>>a>>b;
		if(a=="END" && b=="END") return 0;
		int l1,l2,i,j,dem1=1;
		l1=a.length(); l2=b.length();
		if(l1!=l2) cout<<"Case "<<k<<": "<<"different"<<endl;
		else
		{
			int s1[l1],m;
			m=a[0];
			s1[0]=a[0];
			for(i=1;i<l1;i++)
			{
				bool flag=true;
				for (j=i-1;j>=0;j--)
				   if(a[i]==a[j])
				   {
				   	flag=false;
				   	break;
				   }
				if(flag==true) 
				{
					int t=a[i];
					s1[k]=t;
					dem1++;
				}
			}
			int c[dem1];
			for (i=0;i<dem1;i++) c[i]=0;
			for (i=0;i<dem1;i++)
			{
				for (j=0;j<l1;j++)
				 {
				 	int p=a[j];
				 	if(p==s1[i]) c[i]++;
				 }
			}
			bool flag1=true;
			for (i=0;i<dem1;i++)
			{
				int tong=0;
				for (j=0;j<l2;j++)
				{
					int q=b[j];
					if(q==s1[i]) tong++;
				}
			    if(tong!=c[i])
			    {
			    	flag1=false;
			    	cout<<"Case "<<k<<": "<<"different"<<endl;
			    	break;
				}
			}
			if(flag1==true) cout<<"Case "<<k<<": "<<"same"<<endl;
		}
		k++;
	}
	return 0;
}
