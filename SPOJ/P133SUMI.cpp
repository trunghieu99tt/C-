  /*
	Bước 1: tìm R,C: 
		Cho biến i chạy từ 1 đến căn(n) nếu n%i thì gán r=i, c=n/i, nếu r>c thì break;
	Bước 2: khởi tạo 1 ma trận kí tự hàng=r, cột=c;
		2 vòng for, vòng ngoài là cột, vòng trong là hàng (vì thư được mã hóa theo kiểu viết theo cột)
	Bước 3: xuất thôi.:v
 */
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int i,n=s.length(),max=0,j,r,c;
	for (i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			r=i;
			c=n/i;
			if(r>c) break;
		}
	}
	char a[r][c];
	int k=0;
	for (j=0;j<c;j++)
	{
		for (i=0;i<r;i++) 
		{
			a[i][j]=s[k];
			k++;
		}
	}
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++) cout<<a[i][j];
	}
	return 0;
}