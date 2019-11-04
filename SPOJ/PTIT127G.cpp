/*
	Thuật toán: 
	+ Duyệt từng dòng của đoạn văn đó. ở mỗi dòng duyệt xâu đó, tạo 1 biến j=0 mỗi dòng
	nếu kí tự thứ j là số và j< độ dài của xâu ở hàng đó  thì bắt đầu khởi tạo 1 xâu c, trong khi kí tự thứ j còn là 
	số thì bỏ vào c và tăng j
	+ push c vào vector xâu b;
	+Chuẩn hóa lại các phần tử của mảng ( cho mất số 0 ở đầu ) nếu số nào thuần 0 thì chỉ giữ lại số 0 đầu tiên.
	+ Sắp xếp lại vector ( chú ý so sánh của xâu kí tự khác so sánh với số nên phải làm thủ công, k dùng hàm sort );
	nếu không có thì xuất luôn.
	+Xuất vector.=> done.
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int kt(string s)
{
	int i;
	for (i=0;i<s.length();i++) if(s[i]!='0') return 1;
	return 0;
}
string chuanhoa(string s)
{
	int i=0,j;
	string c="";
	if(kt(s)==1)
	{
		while(s[i]=='0') i++;
	}
	for (j=i;j<s.length();j++) c+=s[j];
		return c;
}
string chuanhoa1(string s)
{
	string c="";
	c+=s[0];
	return c;
}
int main()
{
	int n;
	cin>>n;
	bool flag,flag1;
	vector<string> b;
	string a[n];
	int i,j,k;
	for (i=0;i<n;i++)
		cin>>a[i];
	for (i=0;i<n;i++)
	{
		j=0;
		while(j<a[i].length())
		{
			if(a[i][j]-'0'>=0 && a[i][j]-'0'<=9)
			{
				string c="";
				while(a[i][j]-'0'>=0 && a[i][j]-'0'<=9)			
					{
						c+=a[i][j];
						j++;
					}
				b.push_back(c);
			}
			else j++;
		}
	}
	for (i=0;i<b.size();i++) 
	{
		if(kt(b[i])==1) b[i]=chuanhoa(b[i]);
		else b[i]=chuanhoa1(b[i]);
	}
	for (i=0;i<b.size()-1;i++)
	{
		for(j=i+1;j<b.size();j++)
		{
			if(b[i].length()>b[j].length()) swap(b[i],b[j]);
			else if(b[i].length()==b[j].length() && b[i]>b[j]) swap(b[i],b[j]);
		}
	}
	for (i=0;i<b.size();i++) cout<<b[i]<<endl;
	return 0;
}