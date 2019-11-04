#include<iostream>
using namespace std;
int vitri(int a[], string b[], int n, string c, int k)
{
	int i,dem=0;
	for (i=0;i<n;i++) 
	{
		if(a[i]>k) dem++;
		else if(a[i]==k && b[i]<c) dem++;
	}
	return dem+1; 
}
int main()
{
	int t;
	cin>>t;
	for (int l=0;l<t;l++)
	{
		int n,i,vitri1,vitri2,kq1,kq2,kq3;
		cin>>n;
		string a, b;
		cin>>a>>b;
		string c[n];
	     int d[n];
		for (i=0;i<n;i++) 
		{
			cin>>c[i]>>d[i];
				if(c[i]==a) vitri1=i;
			else if(c[i]==b) vitri2=i;
		}
		d[vitri1]+=3;
		kq1=vitri(d,c,n,c[vitri1],d[vitri1]);
		d[vitri1]-=2;d[vitri2]+=1;
		kq2=vitri(d,c,n,c[vitri1],d[vitri1]);
		d[vitri1]-=1; d[vitri2]+=2;
		kq3=vitri(d,c,n,c[vitri1],d[vitri1]);
		cout<<kq1<<" "<<kq3<<" "<<kq2<<endl;
	}
}
