/*
 	Thuật toán: 
 	+Khởi tạo xâu ( bài này may là số không quá lớn nên cứ duyệt trâu từng số, chuyển qua kí tự rồi cộng vào xâu thôi. nếu số 
 	to thì thuật toán này sẽ bị TLE)
 		++ Chú ý : ví dụ như số 12 thì 1 và 2 phải là 2 kí tự chiếm 2 vị trí của xâu chứ k phải 1
 	+ Bước 2 thì tạo 1 biến i để xác định xem lần xóa đó là chẵn hay lẻ thôi. khởi tạo thêm 1 xâu b nữa để lưu tạm giá trị
 	của xâu sau khi xóa.
 */
#include<iostream>
using namespace std;
int i,j;
string xay(int n)
{
	string s="";
	for (i=1;i<=n;i++) 
		{
			if(i<10) s+=(i+'0');
			else
			{
				int tam=i;
				string b="";
				while(tam>0)
				{
					b+=(tam%10)+'0';
					tam/=10;
				}
				for (j=b.length()-1;j>=0;j--) s+=b[j];
			}
		}
	return s;
}
int main()
{
	int t,k;
	cin>>t;
	for (k=0;k<t;k++)
	{
		int n;
		cin>>n;
		string s=xay(n);
		i=1;
		while(s.length()!=1)
		{
			string b="";
			if(i%2!=0)
				{
					for (j=0;j<s.length();j++) if((j+1)%2!=0) b+=s[j];
				}
			else 
			{
				for (j=0;j<s.length();j++) if((j+1)%2==0) b+=s[j];
			}
			s=b;
			i++;
		}
		cout<<s<<endl;
	}
}