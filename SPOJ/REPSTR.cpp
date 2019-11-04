/*
	Thuật toán: Sắp xếp lại xâu s theo thứ tự giảm dần( dùng hàm sort trong algorithm);
		Khởi tạo 2 biến i và j đều=0, duyệt theo xâu a, nếu kí tự thứ i của a nhỏ hơn kí tự thứ j của s thì tăng i và j
		 nếu không thì tăng i.=> done
	Lưu ý k nên sắp xếp theo cách thông thường vì sẽ bị TLE.~~
 */
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string a,s,max;
	cin>>a;
	cin>>s;
	int i,j,n=s.length();
	sort(s.begin(), s.end(),greater<char>());
	i=0;j=0;
	while(i<a.length() && j<s.length())
	{
		if(a[i]<s[j]) 
		{
			a[i]=s[j];
			i++;
			j++;
		}
		else
			i++;

	}
	cout<<a;
}