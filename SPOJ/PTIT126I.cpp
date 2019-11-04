/*
	Thuật toán:
	Tìm vị trí kí tự giống nhau xuất hiện đầu tiên của 2 xâu A,B gán vào 2 biến vitri,vitri1;
	duyệt theo hàng (m hàng, m là độ dài xâu B) nếu là vị trí xuất hiện của kí tự giống nhau kia trong xâu
	B thì xuất xâu a, không thì xuất theo quy luật.
 */
#include<iostream>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	int n=a.length(),m=b.length(),i,j,vitri,vitri1;
	for (i=0;i<a.length();i++)
	{
		bool flag=false;
		for (j=0;j<b.length();j++)
			 if(a[i]==b[j])
			{
				flag=true;
				vitri=j;			// vitri: vị trí xuất hiện đầu tiên của kí tự giống nhau của 2 xâu A,B trong xâu B
				vitri1=i;			//vitri1: vị trí xuất hiện đầu tiên của kí tự giống nhau của 2 xâu A,B trong xâu A
				break;
			}
		if(flag==true) break;
	}
	for (i=0;i<m;i++)
	{
		if(i==vitri) 
		{
			cout<<a;
			cout<<endl;
		}
		else
		{
			for (j=0;j<vitri1;j++)
				cout<<".";
			cout<<b[i];
			for (j=vitri1+1;j<n;j++) cout<<".";
			cout<<endl;
		}
	}
	return 0;
}