/*
	Thuật toán:
	Tạo mảng các số ;
	Thiết lập điều kiện vô nghiệm
	Tìm số lớn: Duyệt từ cuối mảng số về đầu, nếu s lớn hơn số đó thì thêm số đó vào chuỗi (số lớn) 
	Tìm số bé: Đảo ngược lại chuỗi số lớn 
	+ nếu có số 0 ở đầu thi duyệt lại chuỗi số lớn tìm phần tử đầu tiên kể từ cuối chuỗi số lớn khác 0 thì giảm số đó xuống 1
	và cho phần tử cuối cùng của chuỗi số lớn =1. xuất chuỗi theo thứ tự ngược lại=> done
 */
#include<iostream>
using namespace std;
int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9},i,m,s;
	cin>>m>>s;
	if(m==1 && s==0) cout<<-1<<" "<<-1;
	else if(s==0 || s>9*m) cout<<-1<<" "<<-1;
	else
	{
		i=m;
		string b="";
		int j=9;
		while(i>0)
		{
			if(s>=a[j])
			{
				b+=(a[j]+'0');
				s-=a[j];
				i--;
			}
			else j--;
		}
		string c="";
		string d="";				// d là mảng lưu tạm giá trị của chuỗi số lớn 
		for (i=0;i<b.length();i++) d+=b[i];
		if(b[b.length()-1]=='0')
		{
			for (i=b.length()-1;i>=0;i--) if(b[i]-'0'!=0) 
			{
				b[i]=(b[i]-'0'-1)+'0';									// xử lí số 0 ở đầu chuỗi số bé
				break;
			}
			b[b.length()-1]='1';
		}
		for (i=b.length()-1;i>=0;i--) c+=b[i];
		cout<<c<<" "<<d;
	}
	return 0;
}