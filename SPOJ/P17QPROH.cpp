/*
	Thuật toán: Sắp xếp lại 2 mảng, 1 mảng tăng dần, 1 mảng giảm dần rồi nhân thôi.
	Chú ý bài này xuất có Case nên phải chú ý xuất đúng theo chuẩn của đề bài. khoảng cách Case , #,: đúng chuẩn k là sai.
 */
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t,k;
	cin>>t;
	for (k=1;k<=t;k++)
	{
		int n;
		cin>>n;
		long long kq=0;
		long long a[n],b[n],i;
		for (i=0;i<n;i++) cin>>a[i];
			for (i=0;i<n;i++) cin>>b[i];
		sort(a,a+n,greater<long long>());
		sort(b,b+n);
		for (i=0;i<n;i++)
			kq+=(a[i]*b[i]);
		cout<<"Case #"<<k<<": "<<kq<<endl;
	}
}