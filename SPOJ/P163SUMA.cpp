#include<iostream>
using namespace std;
void sapxep(int a[], int n)
{
	int i,j,tam;
	for (i=0;i<n-1;i++)
	{
		for (j=i+1;j<n;j++)
		 if(a[i]<a[j])
		 {
		 	tam=a[i];
		 	a[i]=a[j];
		 	a[j]=tam;
		 }
	}
}
string s;
char a[100001];
int main()
{
		int n,k,i,j,l=0,dem=1;
	cin>>n>>k;
	cin>>s;
	a[0]=s[0];
	for (i=1;i<s.length();i++)
	{
		bool flag=true;
		for (j=i-1;j>=0;j--)
		  if(s[i]==s[j])
		  {
		  	flag=false;
		  	break;                                // tao mang cac ki tu khac nhau trong xâu
		  }
		if(flag==true) 
		{
			a[++l]=s[i];
			dem++;
		}
	}
	int c[dem];
	for (i=0;i<dem;i++)
	{
		int dem1=0;
		for (j=0;j<s.length();j++)            // tao mang dem so lan xuat hien ung voi moi ki tu khac nhau trong xau
		  if(s[j]==a[i]) dem1++;
		c[i]=dem1;
	}
	sapxep(c,dem);                   // sap xep mang dem giam dan
	i=0;
	long long kq=0;
    while(k!=0)
	{
		if(k>= c[i])
	    {
	    	k-=c[i];
	    	if(c[i]>1) kq+=c[i]*c[i];                // xu li bai toan
	        else kq+=c[i];
	      i++;
		}
		else
		{
			kq+=k*k;
			k=0;
			break;
		}
	 } 
	cout<<kq;
	return 0;
}
