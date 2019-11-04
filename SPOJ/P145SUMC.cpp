/*
	Thuật toán: áp dụng vector +sort
	Tạo 1 mảng vector gồm các ước chung của a và b
	Sắp xếp lại mảng đó (dùng hàm sort)
	Với mỗi test cho chạy từ cuối mảng về đầu, gặp phần tử nào thuộc đoạn đó thì in ra luôn+break;
	nếu k gặp phần tử nào thuộc mảng đó thì cout<<-1;
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	vector <long long> uoc;
	long a,b,i;
	cin>>a>>b;
	if(a>b) swap(a,b);				// lấy thằng bé hơn để xét ước.:v
	for (i=1;i<sqrt(a);i++) 
	{
		if(a%i==0) 
		{
			if(b%i==0)uoc.push_back(i);
			if(b%(a/i)==0) uoc.push_back(a/i);
		}
	}
	long k=sqrt(a);
	if(k*k==a && b%k==0) uoc.push_back(k);
	sort(uoc.begin(),uoc.end());
	int m,l1;
	cin>>m;
	for (l1=0;l1<m;l1++)
	{
		bool flag=false;
		long l,r;
		cin>>l>>r;
		for (i=uoc.size()-1;i>=0;i--) 
		   {
		   	if(uoc[i]<=r && uoc[i]>=l)
				{
					flag=true;
					cout<<uoc[i]<<endl;
					break;
				}
			else if(uoc[i]<l && flag==false) 
				{
					cout<<-1<<endl;
					break;
				}
		   }
	}
}