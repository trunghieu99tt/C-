/*
	Thuật toán cho ma trận xoắn ốc:
	Khởi tạo 1 biến d=0, hàng=n-1, cot=n-1;
	Duyệt dần cho đến khi d=n/2;
	Trong mỗi lần duyệt thì:
	+ Duyệt hàng trước. sau đến duyệt cột, rồi lại duyệt hàng, rồi lại cột. nhớ là thứ tự phải theo chiều xoắn ốc. 
	Cụ thể thì đọc code để biết thêm chi tiết.~~
 */
#include<iostream>
using namespace std;
int main()
{
	int t,k;
	cin>>t;
	for (k=0;k<t;k++)
	{
		int a[100][100],i,j,hang,cot,n,d,gt=1,x,y;
		cin>>n>>x>>y;
		hang=n-1; cot=n-1;d=0;
		while(d<=n/2)
		{
			for (i=d;i<=cot;i++) a[d][i]=gt++;
				for (i=d+1;i<=hang;i++) a[i][cot]=gt++;
					for (i=cot-1;i>=d;i--) a[hang][i]=gt++;
						for (i=hang-1;i>d;i--) a[i][d]=gt++;
			d++;hang--;cot--;
		}
		cout<<a[x-1][y-1]<<endl;
	}
}