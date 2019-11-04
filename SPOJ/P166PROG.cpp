/*
	Thuật toán : Duyệt từ đầu đến cuối của 2 xâu
	So sánh lần lượt mỗi kí tự của 2 xâu trong mỗi lần duyệt, nếu số nào nhỏ hơn thì cộng thêm 10 rồi trừ cho số lớn
	sau đó so sánh với hiệu của số lớn với số bé (số chưa cộng thêm 10) cái nào nhỏ hơn thì lấy.
 */
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s,t;
	int i,tong=0;
	cin>>s>>t;
	for (i=0;i<n;i++)
	{
		int k1,k2;
		k1=s[i]-'0';			// char to num
		k2=t[i]-'0';
		if(k1>k2)
		{
			if((k2+10-k1)>(k1-k2)) tong+=(k1-k2); else tong+=(k2+10-k1);
		}
		else
		{
			if((k1+10-k2)>(k2-k1)) tong+=(k2-k1); else tong+=(k1+10-k2);
		}
	}
	cout<<tong;
}